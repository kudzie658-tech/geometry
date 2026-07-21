#include "Expression"

class Polynomial: public Expression
{
  std::vector<double> m_roots(get_degree()-1);
  
  public:
  Polynomial(int degree, std::vector<double>& coefficients, double roots)
    : Expression(degree, coefficients), m_roots{roots}{}
  
  Polynomial(const Polynomial& p)
    : Expression(get_degree(), get_coefficients()), m_roots{p.get_roots()}{}
  
  double function_of(double x)
  {
    std::vector<double>& coefficients= get_coefficients();
    int degree = get_degree();
    double f_of_x = 0;
    for(auto& coefficient : coefficients)
      {
        f_of_x += coefficient * Geometry::pow(x, --degree);
      }
    return f_of_x;
  }

  std::vector<double>& get_roots(){ return m_roots; }
  
};