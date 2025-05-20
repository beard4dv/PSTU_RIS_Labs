#include <iostream>
#include "windows.h"
#include <locale>

//  Перегруженная функция для сложения обыкновенных дробей
void addFractions(int num1, int denom1, int num2, int denom2, int& resultNum, int& resultDenom)
{
    resultNum = (num1 * denom2) + (denom1 * num2);
    resultDenom = denom1 * denom2;
}

//  Перегруженная функция для сложения десятичных дробей
double addFractions(double num1, double num2)
{
    return num1 + num2;
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    std::cout << "Работа с десятичными дробями" << std::endl;
    double decimal1, decimal2;
    std::cout << "Введите две дроби: ";
    std::cin >> decimal1 >> decimal2;
    double decimalResult = addFractions(decimal1, decimal2);
    std::cout << "\nСумма десятичных дробей: " << decimalResult << std::endl;

    std::cout << "Работа с обыкновенными дробями" << std::endl;
    int a, b, c, d, resultNum, resultDenom;
    char l;
    std::cout << "Введите первую дробь: ";
    std::cin >> a >> l >> b;
    std::cout << "Введите вторую дробь: ";
    std::cin >> c >> l >> d;
    addFractions(a, b, c, d, resultNum, resultDenom);
    std::cout << "\nСумма равна " << resultNum << "/" << resultDenom;
    std::cout << std::endl;

    return 0;
}
