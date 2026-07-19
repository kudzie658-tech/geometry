#include <sstream>

class Linear: public Expression
{
private:
    //Helper functions
     double sub_y(double y) const
    {
        if (get_gradient_m() == 0) return std::numeric_limits<double>::quiet_NaN(); // Horizontal line
        return (y - get_const_c()) / get_gradient_m();
    }

    double sub_x(double x) const
    {
        return (get_gradient_m() * x + get_const_c());
    }

public:
    //Constructor
    Linear(const Point& p1, const Point& p2): Expression(p1, p2)
    {
        std::stringstream ss;
        double c = get_const_c();
        const std::string SIGN = (c > 0) ? " + " : " - ";
        ss << "y = " << get_gradient_m() << "x" << SIGN << Geometry::mod(c);
        set_expression(ss.str());
    }

    //Member functions
    std::string expression() const { return get_expression(); }
    double x_when_y_is(double y) const { return sub_y(y); }
    double y_when_x_is(double x) const { return sub_x(x); }
};
