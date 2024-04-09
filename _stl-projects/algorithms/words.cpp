#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_set>

using std::cout;
using std::cerr;
using std::endl;
using std::string;
using std::unordered_set;
using std::ifstream;
using std::istringstream;

int main() 
{
    // Откроем файл на чтение
    ifstream inputFile("input.txt");
    if (!inputFile) {
        cerr << "Произошла ошибка при открытии файла" << endl;
        return 1;
    }

    unordered_set<string> uniqueWords;

    // Прочтем файл, добавим в список
    string line;
    while (getline(inputFile, line)) {
        istringstream iss(line);
        string word;
        while (iss >> word) {
            // Избавимся от пунктуации
            while (!word.empty() && ispunct(word.back())) {
                word.pop_back();
            }
            uniqueWords.insert(word);
        }
    }

    // Печать списка, конец
    cout << "Уникальные слова:" << endl;
    for (const string& word : uniqueWords) {
        cout << word << endl;
    }

    return 0;
}