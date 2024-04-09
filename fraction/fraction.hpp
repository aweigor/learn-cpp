//
//  fraction.hpp
//  fraction
//
//  Created by igor on 03.12.2023.
//

#ifndef fraction_hpp
#define fraction_hpp

#include <stdio.h>

class Fraction
{
public:
  
  Fraction(long n, long d);
  
  long getNominator() const;
  long getDenominator() const;
  
  bool reduce(void);
  
  bool operator>(const Fraction& other) const;
  bool operator<(const Fraction& other) const;
  bool operator>=(const Fraction& other) const;
  bool operator<=(const Fraction& other) const;
  bool operator==(const Fraction& other) const;
  bool operator!=(const Fraction& other) const;
  
  Fraction operator+(const Fraction& other) const;
  Fraction operator*(const Fraction& other) const;
  Fraction operator-(const Fraction& other) const;
  Fraction operator/(const Fraction& other) const;
  
  friend std::ostream& operator<<(std::ostream& stream, const Fraction& f);
  
  void print(std::ostream& stream) const;

private:
  /**
    numerator, denominator
   **/
  long n_;
  long d_;
  
  long static gcd(long n, long d);
  
};

#endif /* fraction_hpp */
