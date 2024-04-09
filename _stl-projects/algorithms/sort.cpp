#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;
using std::vector;

struct DataStruct {
    int key1;
    int key2;
    string str;
};

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

string generateRandomString(const vector<string>& table) {
    int index = generateRandomNumber(0, table.size() - 1);
    return table[index];
}

// Функциональный объект для сравнения DataStruct
struct CompareDataStruct {
    bool operator()(const DataStruct& a, const DataStruct& b) const {
        if (a.key1 != b.key1) {
            return a.key1 < b.key1;
        } else if (a.key2 != b.key2) {
            return a.key2 < b.key2;
        } else {
            return a.str < b.str;
        }
    }
};

int main() 
{
    // Инициализировать генератора
    srand(time(0)); 

    vector<string> Table = {"Apple", "Banana", "Orange", "Grapes", "Pineapple",
                            "Strawberry", "Watermelon", "Kiwi", "Mango", "Peach"};

    // Заполнить вектор случайными ключами (от -5 до 5)
    vector<DataStruct> dataVector;
    for (int i = 0; i < 10; ++i) {
        DataStruct newData;
        newData.key1 = generateRandomNumber(-5, 5);
        newData.key2 = generateRandomNumber(-5, 5);
        newData.str = generateRandomString(Table);
        dataVector.push_back(newData);
    }


    cout << "Вектор DataStruct перед сортировкой:" << endl;
    for (const DataStruct& data : dataVector) {
        cout << "key1: " << data.key1 << ", key2: " << data.key2 << ", str: " << data.str << endl;
    }
    cout << endl;

    // Sort DataStruct vector
    sort(dataVector.begin(), dataVector.end(), CompareDataStruct());

    // Print sorted DataStruct vector
    cout << "Вектор DataStruct после сортировки:" << endl;
    for (const DataStruct& data : dataVector) {
        cout << "key1: " << data.key1 << ", key2: " << data.key2 << ", str: " << data.str << endl;
    }

    return 0;
}