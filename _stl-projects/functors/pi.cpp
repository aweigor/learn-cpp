#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using std::endl;
using std::cout;
using std::transform;
using std::vector;

// Умножает каждый элемент списка на число PI
void multiplyByPi(vector<double>& nums) 
{
    transform(nums.begin(), nums.end(), nums.begin(),
                   [](double x) { return x * M_PI; });
}

int main() 
{
    vector<double> numbers = { 1.0, 2.0, 3.0, 4.0, 5.0 };

    cout << "Начальные значения:" << endl;
    for (double num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    // Умножим числа на Pi
    multiplyByPi(numbers);

    // Печать результата, конец
    cout << "Числа, умноженные на Pi:" << endl;
    for (double num : numbers) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}