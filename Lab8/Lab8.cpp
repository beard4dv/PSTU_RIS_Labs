#include <iostream>
#include <stdio.h>
#include "windows.h"
#include "locale"

// Инициализация структуры данных пациентов
struct patient
{
    char surname[20];
    char name[20];
    char patronymic[20];
    char homeAddress[50];
    int medCardNumber;
    int insPolNumber;
};

// Функци ввода данных пациента
patient gets()
{
    patient p;
    bool error = true;
    std::cout << "Введите данные пациента.\n";
    std::cout << "Фамилия: "; std::cin >> p.surname;
    std::cout << "Имя: "; std::cin >> p.name;
    std::cout << "Отчество: "; std::cin >> p.patronymic;
    std::cout << "Адрес: "; std::cin >> p.homeAddress;
    while (error)
    {
        std::cout << "Номер медкарты: "; std::cin >> p.medCardNumber;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Ошибка: введен некорректный символ. Введите число.\n";
        }
        else
        {
            std::cin.ignore(1000, '\n');
            error = false;
        }
    }
    error = true;
    while (error)
    {
        std::cout << "Номер страхового полиса: "; std::cin >> p.insPolNumber;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Ошибка: введен некорректный символ. Введите число.\n";
        }
        else
        {
            std::cin.ignore(1000, '\n');
            error = false;
        }
    }
    return p;
}

//  Функция создания бинарного файла с данными пациентов
void createData()
{
    FILE* data;
    data = fopen("data.bin", "wb");
    if (!data)
    {
        std::cout << "Ошибка создания файла!!!\n";
        return;
    }
    int n;
    std::cout << "Введите кол-во добавляемых пациентов :";
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        patient p = gets();
        fwrite(&p, sizeof(patient), 1, data);
    }
    fclose(data);
    system("cls");
    std::cout << "Файл создан.\n";
}

//  Функция печати файла с данными пациентов
void printData()
{
    FILE* data;
    data = fopen("data.bin", "rb");
    if (!data)
    {
        std::cout << "Ошибка открытия файла!!!\n";
        return;
    }
    patient p;
    system("cls");
    std::cout << "Список пациентов:\n";
    for (int i = 0; fread(&p, sizeof(patient), 1, data); i++)
    {
        std::cout << i+1 << ": " << "Фамилия: " << p.surname << ", Имя: " << p.name
            << ", Отчество: " << p.patronymic << ", Адрес: " << p.homeAddress
            << ", Номер медкарты: " << p.medCardNumber
            << ", Номер страхового полиса: " << p.insPolNumber << std::endl;
    }
    fclose(data);
}

//  Функция удаления пациента по номеру медкарты
void deletePatient()
{
    FILE* data;
    data = fopen("data.bin", "rb");
    FILE* tempData;
    tempData = fopen("tempdata.bin", "wb");
    if (!data || !tempData)
    {
        std::cout << "Ошибка открытия файлов!!!\n";
        return;
    }
    int delMedCardNumber;
    std::cout << "Введите номер карты удаляемого пациента: "; std::cin >> delMedCardNumber;
    patient p;
    bool found = false;
    for (int i = 0; fread(&p, sizeof(patient), 1, data); i++)
    {
        if (p.medCardNumber == delMedCardNumber)
        {
            found = true;
        }
        else fwrite(&p, sizeof(patient), 1, tempData);
    }
    fclose(data);
    fclose(tempData);
    if (found)
    {
        data = fopen("data.bin", "wb");
        tempData = fopen("tempdata.bin", "rb");
        for (int i = 0; fread(&p, sizeof(patient), 1, tempData); i++)
        {
            fwrite(&p, sizeof(patient), 1, data);
        }
        fclose(data);
        fclose(tempData);
        remove("tempdata.bin");
        system("cls");
        std::cout << "Пациент с номером карты " << delMedCardNumber << " удален.\n";
    }
    else
    {
        system("cls");
        std::cout << "Пациент с номером карты " << delMedCardNumber << " не найден.\n";
        remove("tempData.bin");
    }
}

// Функция добавления двух пациентов в начало файла
void addPatient()
{
    FILE* data;
    data = fopen("data.bin", "rb");
    FILE* tempData;
    tempData = fopen("tempdata.bin", "wb");
    if (!data || !tempData)
    {
        std::cout << "Ошибка открытия файлов!!!\n";
        return;
    }
    patient p1 = gets();
    patient p2 = gets();
    fwrite(&p1, sizeof(patient), 1, tempData);
    fwrite(&p2, sizeof(patient), 1, tempData);
    patient p;
    for (int i = 0; fread(&p, sizeof(patient), 1, data); i++)
    {
        fwrite(&p, sizeof(patient), 1, tempData);
    }
    fclose(data);
    fclose(tempData);
    data = fopen("data.bin", "wb");
    tempData = fopen("tempdata.bin", "rb");
    for (int i = 0; fread(&p, sizeof(patient), 1, tempData); i++)
    {
        fwrite(&p, sizeof(patient), 1, data);
    }
    fclose(data);
    fclose(tempData);
    remove("tempdata.bin");
    system("cls");
    std::cout << "Два пациента добавлены в начало файла\n";
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int selectionMenu;
    std::cout << "###Карты пациентов.###\n";
    do
    {
        std::cout << "Меню:\n";
        std::cout << "1. Создать файл\n";
        std::cout << "2. Вывод данных пациентов\n";
        std::cout << "3. Удалить пациента по номеру медкарты\n";
        std::cout << "4. Добавить двух пациентов в начало\n";    
        std::cout << "0. Выход\n";
        std::cout << "Выберите действие: ";
        std::cin >> selectionMenu;
        switch (selectionMenu)
        {
        case 1: createData(); break;
        case 2: printData(); break;
        case 3: deletePatient(); break;
        case 4: addPatient(); break;
        case 0: std::cout << "Завершение программы..." << std::endl; break;
        default: system("cls"); std::cout << "Ошибка выбора пункта меню\n";
        }
    } while (selectionMenu != 0);
}