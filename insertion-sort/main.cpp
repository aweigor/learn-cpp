//
//  main.cpp
//  insertion-sort
//
//  Created by igor on 17.10.2023.
//

#include <iostream>

void insertionSort(int* arr, int size) {
  int key;
  int j;
  for (int i = 2; i <= SIZE; i++) {
    key = arr[i];
    j = i - 1;
    
  }
}

int main(int argc, const char * argv[]) {
  // insert code here...
  const int SIZE = 5;
  int arr1[SIZE] = {5, 4, 3, 2, 1};
  insertionSort(arr1, SIZE);
  for (int i = 0; i < SIZE; i++) {
    std::cout << arr1[i] << "\n";
  }
  return 0;
}
