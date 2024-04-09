//
//  main.cpp
//  figure
//
//  Created by igor on 12.12.2023.
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include "rectangle.hpp"
#include "triangle.hpp"
#include "point.h"


/*
 Печать информации о фигуре
*/
void printInfo(std::ostream& stream, Shape** f1)
{
}


/*
  Сортировка фигур, используем алгоритм сортировки вставками
*/
void sortShapes(std::array<std::unique_ptr<Shape>, 5>& shapes, int size)
{
  std::unique_ptr<Shape>::pointer key;
  int i = 1, j;
  
  while (i < size)
  {
    key = shapes[i].get();
    j = i - 1;
    while (j >= 0 && shapes[j].get()->getArea() > key->getArea())
    {
      shapes[j + 1].swap(shapes[j]);
      j--;
    }
    i++;
  }
}


/*
 Изобразим условно 5 фигур на плоскости. Зададим область вершинами,
 Впишем в область фигуры, как показано на графике:
 ____________
| \  /  \  / |
|__\/__  \/  |
|  /\  | /\  |
| /  \ |/  \ |
|/    \/    \|
 ------------
*/
int main(int argc, const char * argv[])
{
  /* верх */
  Point tl = {0, 10};
  Point tm = {5, 10};
  Point tr = {10, 10};
  
  /* правая сторона */
  Point rt = {10, 10};
  Point rm = {10, 5};
  Point rb = {10, 0};
  
  /* низ */
  Point bl = {0, 0};
  Point bm = {5, 0};
  Point br = {10, 0};
  
  /* левая сторона */
  Point lt = {0, 10};
  Point lm = {0, 5};
  Point lb = {0, 0};
  
  /*центр*/
  Point m = {5, 5};
  
  /* центральный */
  std::unique_ptr<Shape> T1 = std::make_unique<Triangle>(lb, tm, rb);
  /* левый равнобедренный */
  std::unique_ptr<Shape> T2 = std::make_unique<Triangle>(lb, tl, bm);
  /* правый равнобедренный */
  std::unique_ptr<Shape> T3 = std::make_unique<Triangle>(rb, tr, bm);
  /* квадрат внешний 10 x 10 */
  std::unique_ptr<Shape> R1 = std::make_unique<Rectangle>(lt, rb);
  /* квадрат внутренний 5 x 5 */
  std::unique_ptr<Shape> R2 = std::make_unique<Rectangle>(m, br);
  
  std::array<std::unique_ptr<Shape>, 5> shapes = {
    std::move(T1),
    std::move(T2),
    std::move(T3),
    std::move(R1),
    std::move(R2)
  };
  
  std::unique_ptr<Shape>::pointer figure;
  
  Triangle t1 = Triangle(lb, tm, rb);
  
  Shape* figures[1] { &t1 };
  
  printInfo(std::cout,figures);
  
  
  /* 1. Сортировка фигур по площади */
  sortShapes(shapes, 5);
  
  /* 2. Распечатаем протокол */
  for (int i = 0; i < 5; i++)
  {
    figure = shapes[i].get();
    printInfo(std::cout,figure);
  }
  
  /* 3. Масштабируем, печатаем новые значения */
  for (int i = 0; i < 5; i++)
  {
    double scaleFactor = 2.0;
    figure = shapes[i].get();
    
    std::cout << "\n" <<  "Масштаб: " << scaleFactor << "x";
    
    figure->scale(scaleFactor);
    printInfo(std::cout,figure);
  }
  
  
  return 0;
}
