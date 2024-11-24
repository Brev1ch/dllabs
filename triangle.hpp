#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include <stdexcept>
#include <iostream>
struct point
{
  double x, y;
};
class Triangle
{
public:
  Triangle() 
  {
    a_.x = 0;
    a_.y = 0;
    b_.x = 0;
    b_.y = 0;
    c_.x = 0;
    c_.y = 0;
    lena_ = 0;
    lenb_ = 0;
    lenc_ = 0;
    perimetr_ = 0;
    square_ = 0;
  }
  Triangle(point a, point b, point c)
  {
    a_ = a;
    b_ = b;
    c_ = c;
    lena_ = side_length(b_, c_);
    lenb_ = side_length(a_, c_);
    lenc_ = side_length(a_, b_);
    perimetr_ = perimetr(lena_, lenb_, lenc_);
    square_ = square(lena_, lenb_, lenc_, perimetr_);
  }
  point a_, b_, c_;
  double lena_, lenb_, lenc_;
  double square_, perimetr_;
  void calculate_the_triangle(Triangle & a);
  double side_length(point a, point b);
  double perimetr(double lena_, double lenb_, double lenc_);
  double square(double lena_, double lenb_, double lenc_, double perimetr_);
};
std::istream& operator >> (std::istream& in, Triangle& Triangle)
{
  in >> Triangle.a_.x >> Triangle.a_.y >> Triangle.b_.x >> Triangle.b_.y >> Triangle.c_.x >> Triangle.c_.y;
  Triangle.lena_ = Triangle::side_length(Triangle.b_, Triangle.c_);
  Triangle.lenb_ = Triangle::side_length(Triangle.a_, Triangle.c_);
  Triangle.lenc_ = Triangle::side_length(Triangle.a_, Triangle.b_);
  Triangle.perimetr_ = Triangle::perimetr(Triangle.lena_, Triangle.lenb_, Triangle.lenc_);
  Triangle.square_ = Triangle::square(Triangle.lena_, Triangle.lenb_, Triangle.lenc_, Triangle.perimetr_);
  return in;
}
bool operator == (Triangle& a, Triangle& b)
{
  return (a.lena_ == b.lena_) && (a.lenb_ == b.lenb_) && (a.lenc_ == b.lenc_);
}
bool operator < (Triangle& a, Triangle& b)
{
  return a.square_ < b.square_;
}
void operator += (Triangle& e, double k)
{
  e.a_.x += k;
  e.b_.x += k;
  e.c_.x += k;
  e.a_.y += k;
  e.b_.y += k;
  e.c_.y += k;
}
namespace brevnov{
  void sort_ascending_order(Triangle & e);
  void moveTriangle(Triangle & e, double k);
  bool checkTable(double lena_, double lenb_, double lenc_);
  bool isEqualAreas(Triangle & a, Triangle & b);
}
#endif
