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
void printInfo(std::ostream& stream, Shape*& figure)
{
  stream << "\n" << "Фигура: " << figure->getName();
  stream << "\n" << "Площадь: " << figure->getArea();
  stream << "\n" << "Центр: (" << figure->getCenter().x
         << ", " << figure->getCenter().y << ")\n";
}


/*
  Сортировка фигур, используем алгоритм сортировки вставками
*/
void sortShapes(Shape** figures, int size)
{
  Shape* key;
  int i = 1, j;
  
  while (i < size)
  {
    key = figures[i];
    j = i - 1;
    while (j >= 0 && *figures[j] > *key)
    {
      figures[j + 1] = figures[j];
      j--;
    }
    figures[j + 1] = key;
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
  Point tl = { 0, 10 };
  Point tm = { 5, 10 };
  Point tr = { 10, 10 };
  
  /* правая сторона */
  Point rt = { 10, 10 };
  Point rm = { 10, 5 };
  Point rb = { 10, 0 };
  
  /* низ */
  Point bl = { 0, 0 };
  Point bm = { 5, 0 };
  Point br = { 10, 0 };
  
  /* левая сторона */
  Point lt = { 0, 10 };
  Point lm = { 0, 5 };
  Point lb = { 0, 0 };
  
  /*центр*/
  Point m = { 5, 5 };
  
  Triangle T1 = Triangle(lb, tm, rb);
  Triangle T2 = Triangle(lb, tl, bm);
  Triangle T3 = Triangle(rb, tr, bm);
  Rectangle R1 = Rectangle(lt, rb);
  Rectangle R2 = Rectangle(m, br);
  
  Shape* figures[5] { &T1, &T2, &T3, &R1, &R2 };
  Shape* figure;
  
  /* 1. Сортировка фигур по площади */
  sortShapes(figures, 5);
  
  /* 2. Распечатаем протокол */
  for (int i = 0; i < 5; i++)
  {
    figure = figures[i];
    printInfo(std::cout, figure);
  }
  
  double scaleFactor = -2.0;
  std::cout << "\n" <<  "Масштаб: x" << scaleFactor << "\n";
  
  /* 3. Масштабируем, печатаем новые значения */
  for (int i = 0; i < 5; i++)
  {
    figure = figures[i];
    
    try {
      figure->scale(scaleFactor);
    }
    catch (const std::exception &exc)
    {
      std::cerr << exc.what();
      exit(1);
    }
    
    printInfo(std::cout,figure);
  }
  
  
  return 0;
}
