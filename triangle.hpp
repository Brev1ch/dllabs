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
  Triangle(const point& a = {}, const point& b = {}, const point& c = {}) :
    a_(a), b_(b), c_(c), lena_(side_length(a, b)), lenb_(side_length(b, c)), lenc_(side_length(a, c)), perimetr_(find_perimetr(lena_, lenb_, lenc_)), area_(find_area(lena_, lenb_, lenc_, perimetr_)) {}
  double side_length(point a, point b);
  double find_perimetr(double lena_, double lenb_, double lenc_);
  double find_area(double lena_, double lenb_, double lenc_, double perimetr_);
  void sort_ascending_order();
  bool checkTable();
  friend std::istream& operator >> (std::istream& in, Triangle& tra);
  bool operator == (Triangle& a);
  void operator += (double k);
  bool operator < (Triangle& a);
  void move_output();
private:
  point a_, b_, c_;
  double lena_, lenb_, lenc_;
  double area_, perimetr_;
};
#endif
