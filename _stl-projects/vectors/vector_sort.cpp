#include <iostream>
#include <vector>
#include <random>
#include <iterator>
#include <fstream>
#include <algorithm> // for std::copy
#include <filesystem>
#include <chrono>

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;
using std::vector;
using std::cout;
using std::endl;
using std::generate_n;
using std::back_inserter;
using std::ostream_iterator;


void bsort(vector<int>& vec) {
  long i, j;
  int tmp;
  for (i = 0; i < vec.size(); i++) {
    for (j = 0; j < vec.size() - i - 1; j++) {
      if (vec[j] > vec[j + 1]) {
        tmp = vec[j];
        vec[j] = vec[j - 1];
        vec[j - 1] = tmp;
      }
    }
  }
}

void bsortAt(vector<int>& vec) {
  long i, j;
  int tmp;
  for (i = 0; i < vec.size(); i++) {
    for (j = 0; j < vec.size() - i - 1; j++) {
      if (vec.at(j) > vec.at(j + 1)) {
        tmp = vec.at(j);
        vec.at(j) = vec.at(j - 1);
        vec.at(j - 1) = tmp;
      }
    }
  }
}

constexpr void is(vector<int>::iterator a, vector<int>::iterator b)
{
  using std::swap;
  swap(*a, *b);
}

template<class ForwardIterator>
void selectionSort(ForwardIterator begin, ForwardIterator end) {
  ForwardIterator it1, it2, itm;
  for (it1 = begin; it1 != end; ++it1) {
    itm = it1;
    for (it2 = it1; it2 != end; ++it2) {
      if (*it2 < *itm) {
        itm = it2;
      }
    }
    is(it1, itm);
  }
}

template <class T>
void printVector(const vector<T>& v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
}

vector<int> copyVector(const vector<int>& other) {
  vector<int> v;
  for (int i=0; i<other.size(); i++)  
    v.push_back(other[i]);  
  return v;
}

int main(int argc, const char * argv[])
{
  srand(time(0)); // Инициализация генератора

  // Инициализация случайными значениями от -500 до 500
  int size = 10000;
  vector<int> randomValues(size);
  for (int& num : randomValues) {
      num = rand() % 1001 - 500;
  }

  // Сортируемый вектор
  vector<int> sortee;

  // заполняем произвольными значениями
  sortee = copyVector(randomValues);

  auto t1 = high_resolution_clock::now();
  // ортировка []
  bsort(sortee);
  auto t2 = high_resolution_clock::now();

  /* Getting number of milliseconds as an integer. */
  auto ms_int = duration_cast<milliseconds>(t2 - t1);

  /* Getting number of milliseconds as a double. */
  duration<double, std::milli> ms_double = t2 - t1;

  std::cout << "Длительность сортировки []: " << endl;
  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";

  // заполняем произвольными значениями
  sortee = copyVector(randomValues);
  

  t1 = high_resolution_clock::now();
  // ортировка at
  bsortAt(sortee);
  t2 = high_resolution_clock::now();

  /* Getting number of milliseconds as an integer. */
  ms_int = duration_cast<milliseconds>(t2 - t1);

  /* Getting number of milliseconds as a double. */
  ms_double = t2 - t1;

  std::cout << "Длительность сортировки at: " << endl;
  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";

  // заполняем произвольными значениями
  sortee = copyVector(randomValues);

  t1 = high_resolution_clock::now();
  selectionSort(sortee.begin(), sortee.end());
  t2 = high_resolution_clock::now();

  /* Getting number of milliseconds as an integer. */
  ms_int = duration_cast<milliseconds>(t2 - t1);

  /* Getting number of milliseconds as a double. */
  ms_double = t2 - t1;

  std::cout << "Длительность сортировки итераторами: " << endl;
  std::cout << ms_int.count() << "ms\n";
  std::cout << ms_double.count() << "ms\n";

  
  return 0;
}
