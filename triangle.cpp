#include "triangle.hpp"
#include <cmath>

double Triangle::side_length(point a, point b)
{
  double length_x = std::abs(a.x - b.x);
  double length_y = std::abs(a.y - b.y);
  return std::sqrt(std::pow(length_x, 2.0) + std::pow(length_y, 2.0));
}

double Triangle::perimetr(double lena_, double lenb_, double lenc_)
{
  return lena_ + lenb_ + lenc_;
}

double Triangle::square(double lena_, double lenb_, double lenc_, double perimetr_)
{
  double p = perimetr_ / 2.0;
  return std::sqrt(p * (p - lena_) * (p - lenb_) * (p - lenc_));
}

bool brevnov::checkTable(double lena_, double lenb_, double lenc_)
{
  return (lena_ >= lenb_ + lenc_) || (lenb_ >= lena_ + lenc_) || (lenc_ >= lenb_ + lena_);
}

void brevnov::sort_ascending_order(Triangle & e)
{
  double * a = &e.lena_;
  double * b = &e.lenb_;
  double * c = &e.lenc_;
  double * help = nullptr;
  if (a < b)
  {
    if (a < c)
    {
      if (b > c)
      {
        help = b;
        b = c;
        c = help;
      }
    }
    else
    {
      help = a;
      a = c;
      c = b;
      b = help;
    }
  }
  else
  {
    if (a < c)
    {
      help = a;
      a = b;
      b = help;
    }
    else
    {
      if (c > b)
      {
        help = a;
        a = b;
        b = c;
        c = help;
      }
      else
      {
        help = a;
        a = c;
        c = help;
      }
    }
  }
}
