//
//  shape.hpp
//  figure
//
//  Created by igor on 12.12.2023.
//

#ifndef shape_hpp
#define shape_hpp

#include <stdio.h>
#include <string>
#include "point.h"

class Shape{
  
public:
  Shape();
  virtual ~Shape() = default;
  
  virtual double getArea() const = 0;
  virtual Point getCenter() const = 0;
  virtual void scale(double factor) = 0;
  virtual std::string_view getName() const = 0;
  
  bool operator>(const Shape& other) const;
  
};

#endif /* shape_hpp */
