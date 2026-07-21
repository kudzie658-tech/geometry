#include "Polynomial.hpp"

class Function
{
  Polynomial polynomial;
  
  public:

  virtual void draw() const = 0;
  virtual double f_of_x(double x) const = 0;
  virtual void translate(double x, double y) = 0;
  virtual void rotate(double angle) = 0;
  virtual void stretch(double h) = 0;
  virtual void reflect() = 0;
};