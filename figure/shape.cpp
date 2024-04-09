//
//  shape.cpp
//  figure
//
//  Created by igor on 12.12.2023.
//

#include "shape.hpp"
#include "point.h"
#include <iostream>

Shape::Shape()
{}

/** перегрузим условный оператор сравнения **/
bool Shape::operator>(const Shape& other) const
{
  return getArea() > other.getArea();
}
