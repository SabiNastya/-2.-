#include <iostream>
#include <cmath>
#include <iomanip>
#include <clocale>
using namespace std;

long long fact(int n) {
    if (n < 0) {
        return -1;  // Факториал не определен для отрицательных чисел
    }
    long long result = 1;
    for (int i = 2; i <= n; ++i) {
        result *= i;
    }
    return result;
}

double a(int n, double x) 
{
    if (n == 1) {
        return 1;
    }
    else {
        return pow(- 1, (n-1))* pow(x, 2 * (n-1)) / (fact((n-1) * 2));
    }
}

long double s(int n, double x) 
{
    if (n < 1) {
        return 0;
    }
    return a(n, x) + s(n - 1, x);
}

int main() {
    setlocale(LC_ALL, "Russian");
    long double x;
    int n;

    cout << "Введите значение x: ";
    cin >> x;
    cout << "Введите количество элементов последовательности: ";
    cin >> n;

    cout << "Сумма элементов последовательности: " << fixed << setprecision(15) << s(n, x) << endl;

    return 0;
}