#include <sstream>
#include "Function.hpp"
#include <print>

class Line: public Function
{
  Polynomial m_polynomial;
  Point m_y_intercept;
  Point m_x_intercept;
  double m_graient_m;

public:
  //Constructor
  Linear(const Point& p2, const Point& p2, const Polynomial& P)
    : m_gradient_m(P.get_coefficients()[0]), 
      m_x_intercept{((-1)*const_c()) / m_graient_m}, 
      m_y_intercept{const_c()},
      P{P}{}

  //Getters
  Polynomial get_polynomial(){ return polynomial; }
  double get_x_intercept(){ return m_x_intercept; }
  double get_y_intercept(){ return m_y_intercept; }

  //Setters
  void set_polynomial(const Polynomial& P)
  {
    m_polynomial.set_degree(P.get_degree());
    m_polynomial.set_coefficients(P.get_coefficients());
  }

  void set_x_intercept(double x){ m_x_intercept = x; }
  void set_y_intercept(double y){ m_y_intercept = y; }

  //Inherited Functions
  void draw() const override
  {
    std::println("Line is drawing");
  }
  
  double function_of(double x) const override
  {
    return (m_gradient_m * x + const_c());
  }
  
  virtual void translate(double x, double y)
  {
    std::println("Line translated");
  }
  
  virtual void rotate(double angle) 
  {
    std::println("Line rotated");
  }
  
  virtual void stretch(double h)
  {
    std::println("Line stretched");
    
  }
  virtual void reflect()
  {
    std::println("Line reflected");
  }

  //Member Functions
  double const_c()
  {
    auto coefficients = get_coefficients();
    return coefficients[1];
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
      return f_of_x(x);
  }
};
