#include "Point.hpp"
#include <limits> // For infinity checks

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

    static double pow(double base, int expo)
    {
      if(expo < 0)
        return -1;
      
      if(expo == 0 || base == 1)
        return 1;
      
      if (expo == 1)
        return base;
      
      buffer = base;
      for(int i = 0; i<base; i++)
        buffer *= base;
      return buffer;
    }
  
};
