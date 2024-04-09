//
//  rectangle.hpp
//  figure
//
//  Created by igor on 12.12.2023.
//

#ifndef rectangle_hpp
#define rectangle_hpp

#include <stdio.h>
#include "shape.hpp"

class Rectangle : public Shape
{
public:
  Rectangle(const Point& a, const Point& b);
  
  double getArea() const override;
  Point getCenter() const override;
  void scale(double factor) override;
  std::string_view getName() const override;
  
private:
  static constexpr std::string_view name_ = "Rectangle";
  Point a_;
  Point b_;
  
};

#endif /* rectangle_hpp */
