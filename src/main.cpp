#include <iostream>
#include <sstream>
#include <map>
#include <print>

class Point;
class Expression;
class Geometry;

class Geometry
{
  private:
  double gradient(int x1, int y1, int x2, int y2) //Helper
  {
    return ((y1 - y2)/(x1 - x2));
    }
    
  public:
  Geometry() = 0;
  
  static double mod(double value)
  {
    return (value < 0)? value*(-1): value;
    }
  
  static double gradient(const Point&& A, const Point&& B)
  {
    return gradient(A.x(), A.y(), B.x(), B.y());
    }
   
  static double constantC(const Point&& point, double gradient_m)
  {
    return point.y() - (point.x() * gradient_m);
    }
  
  };
  
  

class Point
{
  int m_x;
  int m_y;
  
  public:
  Point(int x, int y): m_x{x}, m_y{y}{}
  Point(const Point&& p): m_x{p.x()}, m_y{p.y()}{}
  
  int x()
  {
    return m_x;
    }
    
  int y()
  {
    return y;
    }
    
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
    m_x *= h;
    m_y *= h;
    }
  
  };
  
  class Expression
  {
    Point m_p1;
    Point m_p2;
    std::string m_expression;
    double const_c;
    double gradient_m;
    
    double sub_y(double y)
    {
      return ((y - const_c)/gradient_m);
      }
      
    double sub_x(double x)
    {
      return (gradient_m*x + const_c);
      }
    
    public:
    Expression(const Point&& p1, const Point&& p2): m_p1{p1}, m_p2{p2}
    {
      std::string resultant = "";
      std::sstream ss;
      
      //y = mx + c
      int m = Geometry::gradient(p1, p2);
      int c = Geometry::constantC(p1, m);
      const std::string SIGN =  (c > 0)? " + ": " - ";
      
      ss<< "y = " << m << "x" << SIGN << Geometry::mod(c);
      resultant = ss.str();
      
      const_c = c;
      gradient_m = m;
      m_expression = resultant;
      }
      
      void Print() const
      {
        std::println("Expression: {}", m_expression);
        }
      
      std::string expression() const
      {
        return m_expression;
        }
        
      double x_when_y_is(double y) const
      {
        return sub_y(y);
        }
        
      double y_when_x_is(double x) const
      {
        return sub_x(x);
        }
      
    };

int main() {
  
  Point A{2. 2};
  Point B{3, 3};
  
  Expression line1{A, B};
  
  line.Print();
  
  }
