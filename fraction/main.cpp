#include <iostream>
#include <cassert>
#include "fraction.hpp"

using namespace std;



int main(void)
{
  Fraction f1 = Fraction(1, 2);
  Fraction f2 = Fraction(1, -2);
  
  /** распечатаем исходные значения **/
  std::cout << "f1: ";
  f1.print(std::cout);
  std::cout << std::endl;
  std::cout << "f2: ";
  f2.print(std::cout);
  std::cout << std::endl << std::endl;
  
  /** проверим арифметические операторы **/
  std::cout << "Арифметические действия" << std::endl;
  std::cout << "Сложение: " << (f1 + f2) << std::endl;
  std::cout << "Вычитание: " << (f1 - f2) << std::endl;
  std::cout << "Произведение: " << (f1 * f2) << std::endl;
  std::cout << "Деление: " << (f1 / f2) << std::endl;
  std::cout << std::endl;
  
  /** проверим работу операторов сравнения **/
  std::cout << "Операции сравнения" << std::endl;
  std::cout << ">: " << (f1 > f2) << std::endl;
  std::cout << "<: " << (f1 < f2) << std::endl;
  std::cout << ">=: " << (f1 >= f2) << std::endl;
  std::cout << "<=: " << (f1 <= f2) << std::endl;
  std::cout << "==: " << (f1 == f2) << std::endl;
  std::cout << "!=: " << (f1 != f2) << std::endl;
  std::cout << std::endl;
  
  /** вычтем равные дроби, убедимся, что результат равен 0/1 **/
  Fraction zeroF = f1 - f2;
  std::cout << "Проверка нулевого результата" << std::endl;
  std::cout << "Числитель:" << zeroF.getNominator() << std::endl;
  std::cout << "Знаменатель:" << zeroF.getDenominator() << std::endl;
  std::cout << "Вывод печати:" << zeroF << std::endl;
  std::cout << std::endl;
  
}
