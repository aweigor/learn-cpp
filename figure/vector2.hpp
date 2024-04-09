//
//  vector2.hpp
//  figure
//
//  Created by igor on 12.12.2023.
//

#ifndef vector2_hpp
#define vector2_hpp

#include <stdio.h>
#include "point.h"

struct Vector2 {
  Point a;
  Point b;
  double length;
  Vector2(const Point& a, const Point& b) :
    a(a),
    b(b)
  {
    length = 
  }
  Vector2 setFromPoints(const Point& a, const Point& b) {
    return Vector2(a, b);
  }
  
};

#endif /* vector2_hpp */
