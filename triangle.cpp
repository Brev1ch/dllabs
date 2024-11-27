#include "triangle.hpp"
#include <iostream>
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

bool Triangle::checkTable()
{
  return (lena_ >= lenb_ + lenc_) || (lenb_ >= lena_ + lenc_) || (lenc_ >= lenb_ + lena_);
}

void Triangle::sort_ascending_order()
{
  double a = 0.0, b = 0.0, c = 0.0;
  a = std::max(lena_, lenb_, lenc_);
  c = std::max(lena_, lenb_, lenc_);
  b = (lena_, lenb_, lenc_) - a - c;
  lena_ = a;
  lenb_ = b;
  lenc_ = c;
}

std::istream& Triangle::operator >> (std::istream& in)
{
  in >> a_.x >> a_.y >> b_.x >> b_.y >> c_.x >> c_.y;
  lena_ = side_length(b_, c_);
  lenb_ = side_length(a_, c_);
  lenc_ = side_length(a_, b_);
  perimetr_ = find_perimetr(lena_, lenb_, lenc_);
  area_ = find_area(lena_, lenb_, lenc_, perimetr_);
  return in;
}
bool Triangle::operator == (Triangle& a)
{
  return (a.lena_ == lena_) && (a.lenb_ == lenb_) && (a.lenc_ == lenc_);
}
bool Triangle::operator < (Triangle& b)
{
  return area_ < b.area_;
}
void Triangle::operator += (double k)
{
  a_.x += k;
  b_.x += k;
  c_.x += k;
  a_.y += k;
  b_.y += k;
  c_.y += k;
}

void Triangle::move_output()
{
  std::cout << "Triangle1 moved, new vertices=(" << a_.x << "," << a_.y << ") (" << b_.x << "," << b_.y << ") (" << c_.x << "," << c_.y << ")\n";
}
