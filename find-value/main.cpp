//
//  main.cpp
//  find-value
//
//  Created by igor on 17.10.2023.
//

#include <iostream>

int findValue(int* arr, int size, int needle)
{
  if (size == 1) return arr[0];
  
  int left = arr[size / 2];
  int right = arr[left + 1];
  
  if (needle <= right && needle >= left) {
    return std::abs(needle - left) > std::abs(needle - right) ? right : left;
  }
  
  if (needle < left) {
    return findValue(arr, size / 2, needle);
  }
  
  if (needle > right) {
    return findValue(arr + (size / 2), (size / 2) % size, needle);
  }
  
  return -1;
}

int main(int argc, const char * argv[])
{
  const int S = 5;
  int sorted[S] = {1,3,5,7,9};
  std::cout << findValue(sorted, S, 8) << "\n";
  return 0;
}
