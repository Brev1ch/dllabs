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
    a_(a), b_(b), c_(c), lena_(side_length(a, b)), lenb_(side_length(b, c)), lenc_(side_length(a, c)), perimetr_(find_perimetr(lena_, lenb_, lenc_)), area_(find_area(double lena_, double lenb_, double lenc_, double perimetr_)) {}
  double side_length(point a, point b);
  double find_perimetr(double lena_, double lenb_, double lenc_);
  double find_area(double lena_, double lenb_, double lenc_, double perimetr_);
  void sort_ascending_order(Triangle & e);
  void moveTriangle(Triangle & e, double k);
  bool checkTable(double lena_, double lenb_, double lenc_);
  bool isEqualAreas(Triangle & a, Triangle & b);
  friend std::istream& operator >> (std::istream& in, Triangle& e);
  friend bool operator == (Triangle& a, Triangle& b);
  friend void operator += (Triangle& e, double k);
  friend bool operator < (Triangle& a, Triangle& b);
private:
  point a_, b_, c_;
  double lena_, lenb_, lenc_;
  double area_, perimetr_;
};
#endif
