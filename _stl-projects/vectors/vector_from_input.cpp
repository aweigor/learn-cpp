#include <vector>
#include <iostream>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::copy;
using std::vector;
using std::ostream_iterator;
using std::istream_iterator;

template <class T>
void printVector(const vector<T>& v) {
  copy(v.begin(), v.end(), ostream_iterator<T>(cout, " "));
}

int main () 
{
  int input;
  vector<int> v;

  // считываем стандартный ввод
  while (cin >> input) 
  {
    if (input == 0)
      break;

    v.push_back(input);
  }

  cout << "Содержимое вектора после окончания ввода: " << endl;
  printVector(v);

  if (v.back() == 1)
  {
    for (size_t i = 0; i < v.size(); ++i)
    {
      if (!(v.at(i) & 1))
      {
        v.erase(v.begin() + i);
      }
    }
    cout << "Последнее число 1, удалены все четные элементы: " << endl;
    printVector(v);
  }

  else if (v.back() == 2)
  {
    for (size_t i = 0; i < v.size(); ++i)
    {
      if (!(v.at(i) % 3))
      {
        for (int j = 0; j < 3; ++j) {
          v.insert(v.begin() + i + 1, 1);
        }
      }
    }
    cout << "Последнее число 2, добавлены три единицы: " << endl;
    printVector(v);
  }
  
  return 0;
}