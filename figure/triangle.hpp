//
//  triangle.hpp
//  figure
//
//  Created by igor on 13.12.2023.
//

#ifndef triangle_hpp
#define triangle_hpp

#include <stdio.h>
#include "shape.hpp"

class Triangle : public Shape
{
public:
  Triangle(const Point& a, const Point& b, const Point& c);
  
  double getArea() const override;
  Point getCenter() const override;
  void scale(double factor) override;
  std::string_view getName() const override;
  
private:
  static constexpr std::string_view name_ = "Triangle";
  Point a_;
  Point b_;
  Point c_;
  
};

#endif /* triangle_hpp */
