//
//  point.hpp
//  figure
//
//  Created by igor on 13.12.2023.
//

#ifndef point_hpp
#define point_hpp

#include <stdio.h>

struct Point {
  double x;
  double y;
  Point();
  Point(double x, double y);
  Point sub( const Point& other );
  Point add( const Point& other );
  Point subPoints( const Point& a, const Point& b ) const;
  Point addPoints( const Point& a, const Point& b ) const;
  Point multiplyScalar( double scalar ) const;
  double crossProduct( const Point& other ) const;
};

#endif /* point_hpp */
