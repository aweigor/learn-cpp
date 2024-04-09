#include <iostream>
#include <vector>
#include <fstream>
#include <filesystem>
#include <stdexcept>

using std::cout;
using std::cerr;
using std::endl;
using std::vector;
using std::string;
using std::ios;
using std::ifstream;

void printVector(vector<int> & v) 
{
  for (int n : v)
    cout << n << ' ';
  cout << '\n';
}

vector<int> readFile(const string& fileName) 
{
  int size = 0, input;
  int * array;

  ifstream file(fileName);
  if (!file.is_open())
  {
    cerr << "Ошибка открытия файла\n";
    throw std::bad_exception();
  }

  array = new int [file.tellg()];
  file.seekg(0, ios::beg);

  while (file >> input) {
    array[size++] = input;
  }

  file.close();
  
  // Копирование из массива в вектор одной строкой
  // Указатель будет преобразован в итератор
  vector<int> v(array, array + size);
  
  delete[] array;

  return v;
}

int main() 
{
  vector<int> v = readFile("file.txt");
  cout << "Содержимое вектора после чтения:" << endl;
  printVector(v);
}