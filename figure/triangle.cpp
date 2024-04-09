//
//  triangle.cpp
//  figure
//
//  Created by igor on 13.12.2023.
//

#include "triangle.hpp"
#include <climits>
#include <cstdlib>
#include <iostream>
#include "shape.hpp"
#include "point.h"

Triangle::Triangle(const Point& a, const Point& b, const Point& c) :
/*
 Построим треугольник по трем точкам, определим три вершины
*/
  a_(a),
  b_(b),
  c_(c)
{}

/*
 найдем площадь треугольника
 векторное произведение прилежащих векторов равно
 площади параллелограмма, образуемого ими
 площадь треугольника = 1 / 2
*/
double Triangle::getArea() const
{
  Point s1 = Point().subPoints(a_, b_);
  Point s2 = Point().subPoints(c_, b_);
  
  return std::abs(s1.crossProduct(s2)) * 0.5;
}

/*
 найдем центр треугольника, используем свойство центроида:
 OM = 1/3 ( OA + OB + OC )
*/
Point Triangle::getCenter() const
{
  return Point().addPoints(a_, b_).add(c_)
    .multiplyScalar((double) 1 / (double) 3);
}

/*
 масштабирование, перенесем систему отсчета в центр,
 далее просто умножим векторы вершин на коэффициент
*/
void Triangle::scale(double factor)
{
  Point center = getCenter();
  
  a_ = a_.sub(center).multiplyScalar(factor).add(center);
  b_ = b_.sub(center).multiplyScalar(factor).add(center);
  c_ = c_.sub(center).multiplyScalar(factor).add(center);
}

/*
 Геттер Name
*/
std::string_view Triangle::getName() const
{
  return name_;
}
