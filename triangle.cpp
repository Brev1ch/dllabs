#include "triangle.hpp"
#include <cmath>

double Triangle::side_length(point a, point b)
{
  double length_x = std::abs(a.x - b.x);
  double length_y = std::abs(a.y - b.y);
  return std::sqrt(std::pow(length_x, 2.0) + std::pow(length_y, 2.0));
}

double Triangle::find_perimetr(double lena_, double lenb_, double lenc_)
{
  return lena_ + lenb_ + lenc_;
}

double Triangle::find_area(double lena_, double lenb_, double lenc_, double perimetr_)
{
  double p = perimetr_ / 2.0;
  return std::sqrt(p * (p - lena_) * (p - lenb_) * (p - lenc_));
}

bool Triangle::checkTable(double lena_, double lenb_, double lenc_)
{
  return (lena_ >= lenb_ + lenc_) || (lenb_ >= lena_ + lenc_) || (lenc_ >= lenb_ + lena_);
}

void Triangle::sort_ascending_order(Triangle & e)
{
  double a = 0.0, b = 0.0, c = 0.0;
  a = std::max(e.lena_, e.lenb_, e.lenc_);
  c = std::max(e.lena_, e.lenb_, e.lenc_);
  b = std::sum(e.lena_, e.lenb_, e.lenc_) - a - c;
  e.lena_ = a;
  e.lenb_ = b;
  e.lenc_ = c;
}

std::istream& operator >> (std::istream& in, Triangle& e)
{
  in >> e.a_.x >> e.a_.y >> e.b_.x >> e.b_.y >> e.c_.x >> e.c_.y;
  e.lena_ = Triangle::side_length(e.b_, e.c_);
  e.lenb_ = Triangle::side_length(e.a_, e.c_);
  e.lenc_ = Triangle::side_length(e.a_, e.b_);
  e.perimetr_ = Triangle::find_perimetr(e.lena_, e.lenb_, e.lenc_);
  e.area_ = Triangle::find_area(e.lena_, e.lenb_, e.lenc_, e.perimetr_);
  return in;
}
bool operator == (Triangle& a, Triangle& b)
{
  return (a.lena_ == b.lena_) && (a.lenb_ == b.lenb_) && (a.lenc_ == b.lenc_);
}
bool operator < (Triangle& a, Triangle& b)
{
  return a.area_ < b.area_;
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
