#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using std::cout;
using std::endl;
using std::vector;


vector<double> collectStatistics(const vector<int>& sequence) 
{
    // Используем вектор из 8 элементов для статистики
    vector<double> statistics(8, 0); 

    if (sequence.empty()) {
        return statistics;
    }

    int maximum = sequence[0];
    int minimum = sequence[0];
    double sum = 0;
    int positiveCount = 0;
    int negativeCount = 0;
    double sumOfOdd = 0;
    double sumOfEven = 0;
    bool firstLastEqual = (sequence.front() == sequence.back());

    // Подсчет ститистики
    for (int num : sequence) {
        if (num > maximum) {
            maximum = num;
        }
        if (num < minimum) {
            minimum = num;
        }
        sum += num;
        if (num > 0) {
            positiveCount++;
        } else if (num < 0) {
            negativeCount++;
        }
        if (num % 2 == 0) {
            sumOfEven += num;
        } else {
            sumOfOdd += num;
        }
    }

    // Сохранить статистику
    statistics[0] = maximum;
    statistics[1] = minimum;
    statistics[2] = sum / sequence.size();
    statistics[3] = positiveCount;
    statistics[4] = negativeCount;
    statistics[5] = sumOfOdd;
    statistics[6] = sumOfEven;
    statistics[7] = firstLastEqual;

    return statistics;
}

int main() 
{
    srand(time(0)); // Инициализация генератора

    // Инициализация случайными значениями от -500 до 500
    int size = rand() % 100 + 1;
    vector<int> sequence(size);
    for (int& num : sequence) {
        num = rand() % 1001 - 500;
    }

    // Сбор статистики
    vector<double> statistics = collectStatistics(sequence);

    // Печать статистики, конец
    cout << "Максимум: " << statistics[0] << endl;
    cout << "Минимум: " << statistics[1] << endl;
    cout << "Среднее: " << statistics[2] << endl;
    cout << "Число положительных: " << statistics[3] << endl;
    cout << "Число отрицательных: " << statistics[4] << endl;
    cout << "Число нечетных: " << statistics[5] << endl;
    cout << "Число четных: " << statistics[6] << endl;
    cout << "Первый и последний совпадают?: " << (statistics[7] ? "Да" : "Нет") << endl;

    return 0;
}