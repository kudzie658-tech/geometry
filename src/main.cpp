#include <iostream>
#include "Line.hpp"


class Expression
{
    Point m_p1;
    Point m_p2;
    double m_gradient_m;
    double m_const_c;
    std::string m_expression;
    

    double sub_y(double y) const
    {
        if (m_gradient_m == 0) return std::numeric_limits<double>::quiet_NaN(); // Horizontal line
        return (y - m_const_c) / m_gradient_m;
    }

    double sub_x(double x) const
    {
        return (m_gradient_m * x + m_const_c);
    }

public:
    Expression(const Point& p1, const Point& p2)
        : m_p1{p1}, m_p2{p2},
          m_gradient_m{Geometry::gradient(p1, p2)},
          m_const_c{Geometry::constantC(p1, m_gradient_m)}
    {
        std::stringstream ss;
        const std::string SIGN = (m_const_c > 0) ? " + " : " - ";
        ss << "y = " << m_gradient_m << "x" << SIGN << Geometry::mod(m_const_c);
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
