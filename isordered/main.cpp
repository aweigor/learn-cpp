//
//  main.cpp
//  isordered
//
//  Created by igor on 17.10.2023.
//

#include <iostream>


bool isOrdered(const int* arr, int size) {
  bool ret = true;
  for (int i = 1; i < size; i++) {
    if (arr[i] < arr[i - 1]) {
      ret = false;
      break;
    }
  }
  return ret;
}

int main(int argc, const char * argv[]) {
    // insert code here...
  const int SIZE = 5;
  int arr1[SIZE] = {1,2,3,4,5};
  int arr2[SIZE] = {5,4,3,2,1};
  
  std::cout << isOrdered(arr1, SIZE) << "\n";
  std::cout << isOrdered(arr2, SIZE) << "\n";
  return 0;
}
