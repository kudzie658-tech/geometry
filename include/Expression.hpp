#include "Geometry.hpp"

class Expression
{
  int m_degree;
  std::vector<double> m_coefficients(degree-1);

public:
    void set_degree(int degree){ m_degree = degree; }
    void set_coefficients(std::vector<double>& coefficients)
    { 
      m_coefficients.assign(coefficients.begin(),coefficients.end()); 
    }

    int get_degree(){ return m_degree; }
    std::vector<double> get_coefficients(){ return m_coefficients; }

    Expression(int degree, std::vector<double> coefficients)
      : m_degree{degree}, m_coefficients{coefficients} {}

    virtual void print() const;
    virtual add(const Expression& other_expr);
    virtual subtract(const Expression& other_expr);
    virtual multiply_by(const Expression& other_expr);
    virtual divide_by(const Expression& other_expr);
};

