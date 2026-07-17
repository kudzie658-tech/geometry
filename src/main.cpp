#include <iostream>
#include <sstream>
#include <print>
#include <limits> // For infinity checks

class Point
{
    double m_x;
    double m_y;

public:
    Point(double x, double y) : m_x{x}, m_y{y} {}
    Point(const Point& p) : m_x{p.x()}, m_y{p.y()} {} // Const reference

    double x() const { return m_x; } // Return double, const method
    double y() const { return m_y; }

    void Print() const
    {
        std::println("({}, {})", m_x, m_y);
    }

    void transform(int t_x, int t_y)
    {
        m_x += t_x;
        m_y += t_y;
    }

    void transform(int t_h)
    {
        m_x *= t_h;
        m_y *= t_h;
    }
};

class Geometry
{
private:
    static double gradient(double x1, double y1, double x2, double y2)
    {
        if (x1 == x2) return std::numeric_limits<double>::infinity(); // Handle vertical lines
        return (y1 - y2) / (x1 - x2);
    }

public:
    Geometry() = delete;

    static double mod(double value)
    {
        return (value < 0) ? -value : value;
    }

    static double gradient(const Point& A, const Point& B)
    {
        return gradient(A.x(), A.y(), B.x(), B.y());
    }

    static double constantC(const Point& point, double gradient_m)
    {
        return point.y() - (point.x() * gradient_m);
    }
};

class Expression
{
    Point m_p1;
    Point m_p2;
    double gradient_m;
    double const_c;
    std::string m_expression;
    

    double sub_y(double y) const
    {
        if (gradient_m == 0) return std::numeric_limits<double>::quiet_NaN(); // Horizontal line
        return (y - const_c) / gradient_m;
    }

    double sub_x(double x) const
    {
        return (gradient_m * x + const_c);
    }

public:
    Expression(const Point& p1, const Point& p2)
        : m_p1{p1}, m_p2{p2},
          gradient_m{Geometry::gradient(p1, p2)},
          const_c{Geometry::constantC(p1, gradient_m)}
    {
        std::stringstream ss;
        const std::string SIGN = (const_c > 0) ? " + " : " - ";
        ss << "y = " << gradient_m << "x" << SIGN << Geometry::mod(const_c);
        m_expression = ss.str();
    }

    void Print() const
    {
        std::println("Expression: {}", m_expression);
    }

    std::string expression() const { return m_expression; }
    double x_when_y_is(double y) const { return sub_y(y); }
    double y_when_x_is(double x) const { return sub_x(x); }
};

int main()
{
    Point A{2, 2};
    Point B{3, 3};
    Expression line1{A, B};
    line1.Print(); // Fixed: was 'line.Print()'
}