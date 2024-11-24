#include <iostream>
#include <cmath>
#include "triangle.hpp"

int main()
{
  Triangle triangle1();
  std::cin >> triangle1;
  brevnov::sort_ascending_order(triangle1);
  if (brevnov::checkTable(triangle1.lena_, triangle1.lenb_, triangle1.lenc_))
  {
    std::cerr << "ERROR: it is impossible to construct a triangle from given points\n";
    return 1;
  }
  Triangle triangle2();
  std::cin >> triangle2;
  brevnov::sort_ascending_order(triangle2);
  if (brevnov::checkTable(triangle2.lena_, triangle2.lenb_, triangle2.lenc_))
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
  std::cout << "Triangle1 moved, new vertices=(" << triangle1.a_.x << "," << triangleP1.a_.y << ") (" << triangle1.b_.x << "," << triangle1.b_.y << ") (" << triangle1.c_.x << "," << triangle1.c_.y << ")\n";
  return 0;
}
