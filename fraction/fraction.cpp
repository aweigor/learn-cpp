//
//  fraction.cpp
//  fraction
//
//  Created by igor on 03.12.2023.
//
#include <stdexcept>
#include <numeric>
#include <iostream>
#include "fraction.hpp"

/**
 Конструктор с прямыми параметрами числителя / знаменателя
 **/
Fraction::Fraction(long n, long d) :
  n_(n),
  d_(d)
{
  if (d_ == 0)
  {
    throw std::invalid_argument( "denominator should not be zero" );
  }
  
  if (d_ < 0)
  {
    n_ = -n_;
    d_ = -d_;
  }
}

/**
 Геттер числителя
 **/
long Fraction::getDenominator() const
{
  return d_;
}

/**
 Геттер знаменателя
 **/
long Fraction::getNominator() const
{
  return n_;
}

/**
 Получение наибольшего общего делителя
 **/
long Fraction::gcd(long n, long d)
{
  long remainder;
  while (d != 0)
  {
    remainder = n % d;
    n = d;
    d = remainder;
  }
  return n;
}


/**
 Сокращение дроби
 **/
bool Fraction::reduce(void)
{
  long gcd = Fraction::gcd(n_, d_);

  if (gcd > 1)
  {
    n_ /= gcd;
    d_ /= gcd;
    
    return true;
  }
  return false;
}

/**
 Перегрузка операторов сравнения.
 Избавляемя от дроби переносом знаменателя за знак условного равенства
 **/

/** больше **/
bool Fraction::operator>(const Fraction& other) const
{
  return n_ * other.d_ > d_ * other.n_;
}

/** меньше **/
bool Fraction::operator<(const Fraction& other) const
{
  return n_ * other.d_ < d_ * other.n_;
}

/** больше-равно **/
bool Fraction::operator>=(const Fraction& other) const
{
  return (this->n_ * other.d_) >= (this->d_ * other.n_);
}

/** меньше-равно **/
bool Fraction::operator<=(const Fraction& other) const
{
  return (this->n_ * other.d_) <= (this->d_ * other.n_);
}

/** равно **/
bool Fraction::operator==(const Fraction& other) const
{
  return (this->n_ * other.d_) == (this->d_ * other.n_);
}

/** не равно **/
bool Fraction::operator!=(const Fraction& other) const
{
  return (this->n_ * other.d_) != (this->d_ * other.n_);
}

/**
 Операторы арифметических действий
 Используем сокращение дробей
 Инициализируем новый экземпляр на месте
 **/

/** сложение **/
Fraction Fraction::operator+(const Fraction& other) const
{
  long n = n_ * other.d_ + other.n_ * d_;
  long d = d_ * other.d_;
  
  return Fraction(n/gcd(n,d), d/gcd(n,d)); // this->gcd ?? Fraction::gcd ??
}

/** умножение **/
Fraction Fraction::operator*(const Fraction& other) const
{
  long n = n_ * other.n_;
  long d = d_ * other.d_;
  
  return Fraction(n/gcd(n,d), d/gcd(n,d));
}

/** вычитание **/
Fraction Fraction::operator-(const Fraction& other) const
{
  long n = n_ * other.d_ - other.n_ * d_;
  long d = d_ * other.d_;
  
  return Fraction(n/gcd(n,d), d/gcd(n,d));
}

/** деление **/
Fraction Fraction::operator/(const Fraction& other) const
{
  long n = n_ * other.d_;
  long d = d_ * other.n_;
  
  return Fraction(n/gcd(n,d), d/gcd(n,d));
}

/** Вывод значения в поток **/
std::ostream& operator<<(std::ostream& stream, const Fraction& f)
{
  if (f.d_ == 1)
  {
    stream << f.n_;
  } else
  {
    stream << f.n_ << '/' << f.d_;
  }
  return stream;
}

/** Печать значения **/
void Fraction::print(std::ostream& stream) const
{
  if (d_ == 1)
  {
    stream << this->n_;
  } else
  {
    stream << this->n_ << '/' << this->d_;
  }
}
