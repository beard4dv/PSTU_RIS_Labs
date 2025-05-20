#include <iostream>
#include <stdio.h>
#include "windows.h"
#include "locale"

bool checkWord(const char* buf)
{
    int count = 0;
    bool word = false;
    for (int i = 0; buf[i] != '\0'; ++i)
    {
        if (buf[i] == ' ')
        {
            word = false;
        }
        else if (!word)
        {
            word = true;
            count++;
            if (count > 1) return false;
        }
    }
    return count == 1;
}

void createFile()
{
    FILE* F1;
    F1 = fopen("F1.txt", "w");
    if (!F1)
    {
        std::cout << "Ошибка создания файла!!!\n";
        return;
    }
    char input[255];
    std::cout << "Запись строк в файл F1.txt\n";
    for (int i = 0; i < 10; i++)
    {
        std::cout << "Строка " << i + 1 << "/10: ";
        std::cin.getline(input, sizeof(input));
        fputs(input, F1);
        fputs("\n", F1);
    }
    fclose(F1);
}

void stringCopy()
{
    FILE* F1;
    F1 = fopen("F1.txt", "r");
    FILE* F2;
    F2 = fopen("F2.txt", "w");
    if (!F1 || !F2) 
    {
        std::cout << "Ошибка открытия/создания файла!!!\n";
        return;
    }
    const int MAXLINE = 255;
    char buf[MAXLINE];
    bool check = false;
    while (fgets(buf, MAXLINE, F1))
    {
        if (checkWord(buf))
        {
            check = true;
            fputs(buf, F2);
        }
    }
    fclose(F1);
    fclose(F2);
    if (check)
    {
        std::cout << "Строки с одним словом добалены в файл F2.\n";
    }
    else std::cout << "Строки с одним словом не найдены.\n";
}

void longWord()
{
    FILE* F2;
    F2 = fopen("F2.txt", "r");
    if (!F2)
    {
        std::cout << "Ошибка открытия файла!!!\n";
        return;
    }
    const int MAXLINE = 255;
    char buf[MAXLINE];
    char longWord[MAXLINE] = "\0";
    while (fgets(buf, MAXLINE, F2))
    {
        if (strlen(buf) > strlen(longWord))
        {
            strcpy(longWord, buf);
        }
    }
    std::cout << "Самое длинное слово в файле F2: " << longWord << std::endl;
    fclose(F2);
}

void printFile()
{
    int subMenu;
    char buf[255];
    std::cout << "1. F1\n2. F2\nВыберите файл: "; std::cin >> subMenu;
    switch (subMenu)
    {
    case 1:
    {
        FILE* F1;
        F1 = fopen("F1.txt", "r");
        if (!F1)
        {
            std::cout << "Ошибка открытия файла!!!\n";
            return;
        }
        std::cout << "Cодержимое файла F1\n";
        while (fgets(buf, 255, F1))
        {
            std::cout << buf;
        }
        fclose(F1);
        break;
    }
    case 2:
    {
        FILE* F2;
        F2 = fopen("F2.txt", "r");
        if (!F2)
        {
            std::cout << "Ошибка открытия файла!!!\n";
            return;
        }
        std::cout << "Cодержимое файла F2\n";
        while (fgets(buf, 255, F2))
        {
            std::cout << buf;
        }
        fclose(F2);
        break;
    }
    }

}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int selectionMenu;
    do
    {
        std::cout << "Ввод-вывод строк. Меню:\n";
        std::cout << "1. Создать файл\n2. Копировать строки с одним словом\n3. Вывести самое длинное слово в файле F2\n4. Вывод файлов\nВыберите действие: ";
        std::cin >> selectionMenu;
        std::cin.ignore();
        switch (selectionMenu)
        {
        case 1: createFile(); break;
        case 2: stringCopy(); break;
        case 3: longWord(); break;
        case 4: printFile(); break;
        case 0: std::cout << "Exit..."; break;
        default: std::cout << "Ошибка выбора пункта меню\n";
        }
    } while (selectionMenu != 0);
}