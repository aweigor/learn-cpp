//
//  rectangle.cpp
//  figure
//
//  Created by igor on 12.12.2023.
//

#include "rectangle.hpp"
#include <climits>
#include <cstdlib>
#include "shape.hpp"
#include "point.h"

Rectangle::Rectangle(const Point& a, const Point& b) :
/*
 Построим прямоугольник по двум точкам
*/
  a_(a),
  b_(b)
{}

/*
 найдем площадь прямоугольника = векторное произведение прилежащих сторон
*/
double Rectangle::getArea() const
{
  Point c = Point(a_.x, b_.y);
  Point s1 = Point().subPoints(a_, c);
  Point s2 = Point().subPoints(b_, c);
  
  return std::abs(s1.crossProduct(s2));
}

/*
 найдем центр, используем свойство сложения векторов
*/
Point Rectangle::getCenter() const
{
  return Point().addPoints(a_, b_)
    .multiplyScalar((double) 1 / (double) 2);
}

/*
 масштабирование, перенесем систему отсчета в центр,
 далее просто умножим векторы вершин на коэффициент
*/
void Rectangle::scale(double factor)
{
  /* отрицательный factor!! */
  if (factor < 0) {
    throw std::invalid_argument( "Масштаб должен соделжать положительное вещественное значение." );
  }
  
  const Point center = getCenter();
  
  a_ = a_.sub(center).multiplyScalar(factor).add(center);
  b_ = b_.sub(center).multiplyScalar(factor).add(center);
}

/*
 Геттер Name
*/
std::string_view Rectangle::getName() const
{
  return name_;
}
