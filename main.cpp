#include <iostream>
#include <cmath>
#include "triangle.hpp"

int main()
{
  Triangle triangle1;
  std::cin >> triangle1;  
  triangle1.sort_ascending_order();
  if (triangle1.checkTable())
  {
    std::cerr << "ERROR: it is impossible to construct a triangle from given points\n";
    return 1;
  }
  Triangle triangle2;
  std::cin >> triangle2;
  triangle2.sort_ascending_order();
  if (triangle2.checkTable())
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

std::istream& operator >> (std::istream& in, Triangle& tra)
{
  in >> tra.a_.x >> tra.a_.y >> tra.b_.x >> tra.b_.y >> tra.c_.x >> tra.c_.y;
  tra.lena_ = tra.side_length(tra.b_, tra.c_);
  tra.lenb_ = tra.side_length(tra.a_, tra.c_);
  tra.lenc_ = tra.side_length(tra.a_, tra.b_);
  tra.perimetr_ = tra.find_perimetr(tra.lena_, tra.lenb_, tra.lenc_);
  tra.area_ = tra.find_area(tra.lena_, tra.lenb_, tra.lenc_, tra.perimetr_);
  return in;
}
