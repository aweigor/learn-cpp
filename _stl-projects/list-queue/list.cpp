#include <iostream>
#include <list>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::list;

// Генерирует случайные значения от min до max
int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

// Заполняет список случайными значениями от 1 до 20
void fillListWithRandomNumbers(list<int>& myList, int count) {
    for (int i = 0; i < count; ++i) {
        myList.push_back(generateRandomNumber(1, 20));
    }
}

// Печатает список
void printListInOrder(const list<int>& myList, list<int>::const_iterator it, int index) {
    if (index == 0) {
        cout << *it << " ";
        return;
    }

    if (index == 1) {
        printListInOrder(myList, it, index - 1);
    } else {
        auto nextIt = next(it);
        printListInOrder(myList, nextIt, index - 1);
    }
}

int main() 
{
    srand(time(0)); // инициализация генератора случайных значений

    list<int> myList;

    // заполнить список 15 случайными значениями
    fillListWithRandomNumbers(myList, 15);

    // Печать списка в порядке очередности
    if (!myList.empty()) {
        // Print the first element
        cout << "Первый элемент: " << myList.front() << endl;

        // Print the second element
        if (myList.size() >= 2) {
            auto secondIt = next(myList.begin());
            cout << "Второй элемент: " << *secondIt << endl;
        }

        // Print the last element
        cout << "Последний элемент: " << myList.back() << endl;

        // Print the third element
        if (myList.size() >= 3) {
            auto thirdIt = next(myList.begin(), 2);
            cout << "Третий элемент: ";
            printListInOrder(myList, thirdIt, 2);
            cout << endl;
        }
    } else {
        cout << "Список пуст." << endl;
    }

    return 0;
}