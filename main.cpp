#include <iostream>
#include <cmath>
#include "triangle.hpp"

int main()
{
  Triangle triangle1();
  std::cin >> triangle1;  
  triangle1.sort_ascending_order(triangle1);
  if (triangle1.checkTable())
  {
    std::cerr << "ERROR: it is impossible to construct a triangle from given points\n";
    return 1;
  }
  Triangle triangle2();
  std::cin >> triangle2;
  triangle1.sort_ascending_order(triangle1);
  if (triangle1.checkTable())
  {
    std::cerr << "ERROR: it is impossible to construct a triangle from given points\n";
    return 1;
  }
  if (triangle1 == triangle2)
  {
    std::cout << "The triangles are equal\n";
  }
  else
  {
    std::cout << "The triangles are not equal\n";
  }
  if (triangle1 < triangle2)
  {
    std::cout << "The area of the first triangle is less than the second\n";
  }
  else
  {
    std::cout << "The area of the first triangle is NOT less than the second\n";
  }
  double k = 0.0;
  std::cin >> k;
  triangle1 += k;
  triangle1.move_output();
  return 0;
}
