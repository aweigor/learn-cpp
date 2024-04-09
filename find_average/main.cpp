# include <iostream>
# include <string>

/* Игорь Новицкий гр.в5130904/20021
 *
 * Массивы, Вариант 19
 * Поиск среднего зачения в массиве
 *
**/

/* Объявления */

/* Выделение памяти под динамический массив */
void allocateDynamicArray(int*& dynArray, int size);

/* Освобождение динамической памяти */
void deallocateDynamicArray(int*& dynArray, int size);

/* Заполнение динамического массива исходными данными */
void loadDynamicData(const int* src, int* dest, int size);

/* Процедура тестирования - создает и удаляет динамические данные, проверяет результат */
void test(int* array, int size, double checkVal);

/* Поиск среднего значение четных элементов массива */
double findEvenElementsAverage(const int* target, int size);




/* Вспомогательные процедуры */

/**/
void allocateDynamicArray(int*& dynArray, int size)
{
  dynArray = new int [size];
}

/**/
void deallocateDynamicArray(int* dynArray)
{
  delete[] dynArray;
}

/**/
void loadDynamicData(const int* src, int* dest, int size)
{
  for (int i = 0; i < size; i++) {
    *(dest + i) = *(src + i);
  }
}

/**/
void test(int* array, int size, double checkVal)
{
  double average;
  int *dynArray = nullptr;
  
  try {
    average = ::findEvenElementsAverage(array, size);
  }
  catch (...)
  {
    std::cerr << "Error!\n";
  }
  
  std::cout << "Результат поиска среднего для обчного массива" << std::endl;
  std::cout << "Искомый результат:" << average << std::endl;
  std::cout << "Проверочное значение:" << checkVal << std::endl;
  std::cout << "Пройдено:" << (checkVal == average) << std::endl;
  std::cout << std::endl;
  
  try {
    ::allocateDynamicArray(dynArray, size);
    ::loadDynamicData(array, dynArray, size);
    average = ::findEvenElementsAverage(dynArray, size);
    
    std::cout << "Результат поиска среднего для динамического массива" << std::endl;
    std::cout << "Искомый результат:" << average << std::endl;
    std::cout << "Проверочное значение:" << checkVal << std::endl;
    std::cout << "Пройдено:" << (checkVal == average) << std::endl;
    std::cout << std::endl;
  }
  catch (...)
  {
    std::cerr << "Error!\n";
  }
  
  ::deallocateDynamicArray(dynArray);
}



/* Основные функции */

/**/
double findEvenElementsAverage(const int* target, int size)
{
  if (size <= 0) {
    return 0;
  }
  
  double sum = *target;

  int i = 1;

  while (i * 2 < size)
  {
    sum += *(target + i * 2);
    
    i++;
  }
  
  return sum / (double)i;
}


/**/
int main (void)
{
  int size;
  double checkVal;
  
  int testArray1[] = {};
  int testArray2[] = {1};
  int testArray3[] = {1, 2};
  int testArray4[] = {1, 2, 3, 4, 5};
  int testArray5[] = {2, 0, 3, 0, 5, 0, 11, 0, 13, 0};
  
  
  size = 0;
  checkVal = 0;
  test(testArray1, size, checkVal);
  
  size = 1;
  checkVal = 1;
  test(testArray2, size, checkVal);
  
  size = 2;
  checkVal = 1;
  test(testArray3, size, checkVal);
  
  size = 5;
  checkVal = (double)(1 + 3 + 5) / (double)3;
  test(testArray4, size, checkVal);
  
  size = 10;
  checkVal = (double)(2 + 3 + 5 + 11 + 13) / (double)5;
  test(testArray5, size, checkVal);
  
  
  
  int testArrayRand[10] = {};
  
  size = 10;
  checkVal = (double)(2 + 3 + 5 + 11 + 13) / (double)5;
  test(testArray5, size, checkVal);
  

  return 0;
}
