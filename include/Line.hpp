#include <sstream>
#include "Polynomial.hpp"

class Line: public Polynomial
{
  Point m_y_intercept;
  Point m_x_intercept;
  double m_graient_m;

public:
    //Constructor
    Linear(const Point& p2, const Point& p2)
      : Geometry::gradient(p1, p2), m_x_intercept{((-1)*const_c()) / m_graient_m}, m_y_intercept{const_c()}
    {}

    //Member functions
  
    double const_c()
    {
        return Geometry::constantC(m_x_intercept, m_graient_m);
    }
  
    std::string expression() const 
    {
        std::stringstream ss;
        double c = const_c();
        const std::string SIGN = (c > 0) ? " + " : " - ";
        ss << "y = " << m_gradient_m << "x" << SIGN << Geometry::mod(c);
        return ss.str();
    }
  
    double x_when_y_is(double y) const 
    {
        if (m_gradient_m == 0) return std::numeric_limits<double>::quiet_NaN(); // Horizontal line
        return (y - const_c()) / m_gradient_m;
    }
  
    double y_when_x_is(double x) const 
    { 
        return (m_gradient_m * x + const_c());
    }
};
