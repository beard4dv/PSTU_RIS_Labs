#include <iostream>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для srand(time(NULL))
#include <windows.h>

// Функция создания двумерного массива
void createArray(int** array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        array[i] = new int[cols];
    }
    srand(time(NULL)); // Инициализация генератора случайных чисел
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            array[i][j] = rand() % 100; // Случайные числа от 0 до 99
        }
    }
}

// Функция печати массива
void printArray(int** array, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            std::cout << array[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Функция создания массива с доп. столбцом
void createNewArray(int** array, int** newArray, int rows, int cols, int newColIndex)
{
    for (int i = 0; i < rows; i++)
    {
        newArray[i] = new int[cols + 1];
    }

    for (int i = 0; i < rows; i++)
    {
        int newIndex = 0;
        for (int j = 0; j < cols + 1; j++)
        {
            if (j == newColIndex)
            {
                newArray[i][j] = rand() % 100; // Заполнение нового столбца случайными числами
            }
            else
            {
                newArray[i][j] = array[i][newIndex++];
            }
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int rows, cols, newColIndex;

    // Ввод размера массива
    std::cout << "Введите количество строк: ";
    std::cin >> rows;
    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;
    
    // Создание и заполнение массива
    int** array = new int* [rows]; 
    createArray(array ,rows, cols);

    // Печать массива
    std::cout << "Исходный массив:\n";
    printArray(array, rows, cols);

    // Добавление столбца с заданным номером
    std::cout << "Введите номер нового столбца (0-" << cols << "): ";
    std::cin >> newColIndex;
    if (newColIndex < 0 || newColIndex > cols)
    {
        std::cout << "Некорректный номер столбца!\n";
        // Очистка памяти перед завершением
        for (int i = 0; i < rows; i++)
        {
            delete[] array[i];
        }
        delete[] array;
        return 0;
    }

    // Создание нового массива с дополнительным столбцом
    int** newArray = new int* [rows];
    createNewArray(array, newArray, rows, cols, newColIndex);
 
    // Печать нового массива
    std::cout << "Массив после добавления нового столбца:\n";
    printArray(newArray, rows, cols + 1);

    // Очистка памяти
    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;
    for (int i = 0; i < rows; i++)
    {
        delete[] newArray[i];
    }
    delete[] newArray;
}