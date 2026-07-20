#include <iostream>
#include "Line.hpp"

int main()
{
    Point A{2, 2};
    Point B{3, 3};
    Expression line1{A, B};
    line1.print()
}