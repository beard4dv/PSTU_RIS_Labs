#include <iostream>
#include <cstdarg>
#include <limits>

//  Функция min с переменным числом пар-ов для посика минимального значения int
int min(int k, int count,...)
{
    va_list arg;
    va_start(arg, count);
    int minNum = std::numeric_limits<int>::max();
    int value;
    for (int i = 1; i <= k; ++i)
    {
        value = va_arg(arg, int);
        if (minNum > value) minNum = value;
    }
    va_end(arg);
    return minNum;
}

//  Функция min с переменным числом пар-ов для посика минимального значения double
double min(double k, double count, ...)
{
    va_list arg;
    va_start(arg, count);
    double minNum = std::numeric_limits<double>::max();
    double value;
    for (int i = 1; i <= k; ++i)
    {
        value = va_arg(arg, double);
        if (minNum > value) minNum = value;
    }
    va_end(arg);
    return minNum;
}

void main()
{
    setlocale(LC_ALL, "Russian");
    int m[13], minNum, k, s = 0, e = 999;
    double md[13], kd;
    std::cout << "Параметры типа int\n";
    k = 5;
    std::cout << "Кол-во параметров: " << k << std::endl;
    for (int i = 1; i <= k; i++) // Присваиваем случайное значение элементам массива
    {
        m[i] = rand() % (e - s + 1) + s;
        std::cout << i << ": " << m[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Минимальное значение пар-ра: " << min(k, m[0], m[1], m[2], m[3], m[4], m[5]) << std::endl; //   Поиск минимального значения из 5 эл-ов int
    k = 10;
    std::cout << "Кол-во параметров: " << k << std::endl;
    for (int i = 1; i <= k; i++)
    {
        m[i] = rand() % (e - s + 1) + s;
        std::cout << i << ": " << m[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Минимальное значение пар-ра: " << min(k, m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10]) << std::endl; //   Поиск минимального значения из 10 эл-ов int
    k = 12;
    std::cout << "Кол-во параметров: " << k << std::endl;
    for (int i = 1; i <= k; i++)
    {
        m[i] = rand() % (e - s + 1) + s;
        std::cout << i << ": " << m[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Минимальное значение пар-ра: " << min(k, m[0], m[1], m[2], m[3], m[4], m[5], m[6], m[7], m[8], m[9], m[10], m[11], m[12]) << std::endl; //   Поиск минимального значения из 12 эл-ов int
    std::cout << "Параметры типа double\n";
    kd = 5;
    std::cout << "Кол-во параметров: " << kd << std::endl;
    for (int i = 1; i <= kd; i++)
    {
        md[i] = (rand() % (e - s + 1) + s) / 1.2;
        std::cout << i << ": " << md[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Минимальное значение пар-ра: " << min(kd, md[0], md[1], md[2], md[3], md[4], md[5]) << std::endl; //   Поиск минимального значения из 5 эл-ов double
    kd = 10;
    std::cout << "Кол-во параметров: " << kd << std::endl;
    for (int i = 1; i <= kd; i++)
    {
        md[i] = (rand() % (e - s + 1) + s) / 1.2;
        std::cout << i << ": " << md[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Минимальное значение пар-ра: " << min(kd, md[0], md[1], md[2], md[3], md[4], md[5], md[6], md[7], md[8], md[9], md[10]) << std::endl; //   Поиск минимального значения из 10 эл-ов double
    kd = 12;
    std::cout << "Кол-во параметров: " << kd << std::endl;
    for (int i = 1; i <= kd; i++)
    {
        md[i] = (rand() % (e - s + 1) + s) / 1.2;
        std::cout << i << ": " << md[i] << "\t";
    }
    std::cout << std::endl;
    std::cout << "Минимальное значение пар-ра: " << min(kd, md[0], md[1], md[2], md[3], md[4], md[5], md[6], md[7], md[8], md[9], md[10], md[11], md[12]) << std::endl; //   Поиск минимального значения из 12 эл-ов double
}