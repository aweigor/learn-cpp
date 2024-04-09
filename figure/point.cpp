//
//  point.cpp
//  figure
//
//  Created by igor on 13.12.2023.
//

#include "point.hpp"
/*
 Структура Point, для целей работы эквивалентна вектору
 Декларация без параметров, единичный вектор
*/
Point::Point() :
  x((double) 1),
  y((double) 1)
{}

Point::Point(double x, double y) :
  x((double) x),
  y((double) y)
{}

/*
 Вычитание локальный контекст
*/
Point Point::sub( const Point& other )
{
  x -= other.x;
  y -= other.y;
  
  return Point(x, y);
}

/*
 Сложение локальный контекст
*/
Point Point::add( const Point& other )
{
  x += other.x;
  y += other.y;

  return Point(x, y);
}

/*
 Вычитание ноый контекст
*/
Point Point::subPoints( const Point& a, const Point& b ) const
{
  return Point({ a.x - b.x, a.y - b.y });
}

/*
 Сложение новый контекст
*/
Point Point::addPoints( const Point& a, const Point& b ) const
{
  return Point({ a.x + b.x, a.y + b.y });
}

/*
 Умножение компонент на число
*/
Point Point::multiplyScalar( double scalar ) const
{
  return Point({ x * scalar, y * scalar });
}

/*
 Векторное произведение
*/
double Point::crossProduct( const Point& other ) const
{
  return x * other.y - y * other.x;
}
