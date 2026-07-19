#include <print>

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