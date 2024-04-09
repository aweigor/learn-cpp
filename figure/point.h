//
//  point.h
//  figure
//
//  Created by igor on 12.12.2023.
//

#ifndef point_h
#define point_h

struct Point {
  double x;
  double y;
  Point(double x, double y) :
    x((double) x),
    y((double) y)
  {}
  Point() :
    x((double) 1),
    y((double) 1)
  {}
  Point sub( const Point& other )
  {
    x -= other.x;
    y -= other.y;
    
    return Point(x, y);
  };
  Point add( const Point& other )
  {
    x += other.x;
    y += other.y;
  
    return Point(x, y);
  };
  Point subPoints( const Point& a, const Point& b )
  {
    return Point({ a.x - b.x, a.y - b.y });
  };
  Point addPoints( const Point& a, const Point& b )
  {
    return Point({ a.x + b.x, a.y + b.y });
  };
  Point multiplyScalar( double scalar )
  {
    return Point({ x * scalar, y * scalar });
  };
  double crossProduct( const Point& other )
  {
    return x * other.y - y * other.x;
  };
  double dotProduct( const Point& other )
  {
    return x * other.x + y * other.y;
  };
};

#endif /* point_h */
