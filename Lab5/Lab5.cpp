#include <iostream>
#include <cstdlib>

int sumMass(int** m, int R) // Функция для вычисления суммы элементов матрицы ниже главной диагонали
{
    int sum = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < R; j++)
        {
            if (i > j) sum += m[i][j];
        }
    }
    return sum;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int n, R, s = -9, e = 9;    // Инициализация переменных кол-ва матриц, размера, диапазона рандомного значения
    std::cout << "Введите кол-во матриц: ";
    std::cin >> n;  // Ввод кол-ва матриц
    int* sumRow = new int[n];   // Инициализация динамического массива сумм элементов матриц
    int sumMax; // Переменная максимального значения суммы
    for (int k = 0; k < n; k++) 
    {
        std::cout << "Введите размер квадратной матрицы: ";
        std::cin >> R;  // Ввод размера квадратной матрицы
        int** m = new int* [R]; //Инициализация динамического массива матрицы
        for (int i = 0; i < R; i++) 
        {
            m[i] = new int[R];
        }
        for (int i = 0; i < R; i++) // Присвоение рандомного значения значениям матрицы
        {
            for (int j = 0; j < R; j++)
            {
                m[i][j] = rand() % (e - s + 1) + s; // Присвоение рандомного значения ячейке массива в диапазоне от s до e
            }
        }
        for (int i = 0; i < R; i++) // Вывод значений матрицы
        {
            for (int j = 0; j < R; j++)
            {
                std::cout << m[i][j] << "\t";
            }
            std::cout << std::endl;
        }

        sumRow[k] = sumMass(m, R);
        std::cout << "Sum: " << sumRow[k] << std::endl; // Вывод сумма элементов матрицы

        for (int i = 0; i < R; i++) // Удаление массива матрицы
        {
            delete[] m[i];
        }
        delete[] m;
        m = nullptr;    // Обнуление указателя
    }
    sumMax = sumRow[0]; 
    for (int i = 0; i < n; i++) // Цикл поиска максимального значения суммы
    {
        if (sumRow[i] > sumMax) sumMax = sumRow[i];
    }
    std::cout << "Максимальное значение в суммы: " << sumMax << std::endl;  // Вывод максимального значения суммы
    delete[] sumRow;    // Удаление массива сумм
    sumRow = nullptr;
}

