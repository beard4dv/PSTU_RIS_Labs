#include <iostream>
#include <string.h>
#include "windows.h"
#include <locale>

void cleanWord(char* word, char* cleanedWord) // Функция для очистки слова от знаков препинания и небуквенных символов
{
    int index = 0;  // Индекс для записи очищенного слова
    for (int i = 0; word[i] != '\0'; i++) 
    {
        if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z') || // Проверяем, является ли символ буквой (латиница или кириллица)
            (word[i] >= 'А' && word[i] <= 'Я') || (word[i] >= 'а' && word[i] <= 'я') || // Также оставляем цифры, которые могут быть частью слова
            (word[i] >= '0' && word[i] <= '9')) 
        { 
            cleanedWord[index++] = word[i]; // Сохраняем только буквы и цифры
        }
    }
    cleanedWord[index] = '\0';  // Завершаем строку нулевым символом
}
void lowerCase(char* word)  // Функция для преобразования строки в нижний регистр
{
    for (int i = 0; word[i] != '\0'; i++) 
    {
        if (word[i] >= 'A' && word[i] <= 'Z')   // Преобразуем символы в нижний регистр
        {
            word[i] = word[i] + ('a' - 'A');    // Преобразование в нижний регистр для латиницы
        }
        else if (word[i] >= 'А' && word[i] <= 'Я')  // Для кириллицы
        {
            word[i] = word[i] + ('а' - 'А');    // Преобразование в нижний регистр для кириллицы
        }
    }
}
bool onlyNumbers(char* word)  // Проверяем, состоит ли слово только из цифр
{
    bool hasNumbers = false;
    bool hasLetters = false;

    for (int i = 0; word[i] != '\0'; i++) 
    {
        if (word[i] >= '0' && word[i] <= '9') 
        {
            hasNumbers = true;  // Есть цифры
        }
        else if ((word[i] >= 'A' && word[i] <= 'Z') || (word[i] >= 'a' && word[i] <= 'z') ||
            (word[i] >= 'А' && word[i] <= 'Я') || (word[i] >= 'а' && word[i] <= 'я')) 
        {
            hasLetters = true;  // Есть буквы
        }
    }
    return hasNumbers && !hasLetters;   // Возвращаем true, если есть только цифры и нет букв
}

bool startsWithNumbers(char* word)    // Проверяем, начинается ли слово с цифр
{
    return (word[0] >= '0' && word[0] <= '9');  // Если первый символ - цифра, возвращаем true
}

bool keywords(char* word) // Проверка, является ли слово ключевым словом, которые нельзя использовать в идентификаторах
{
    const char* keywords[] = 
    {
        "alignas", "alignof", "and", "and_eq", "asm", "auto", "bitand", "bitor", "bool", 
        "break", "case", "catch", "char", "char16_t", "char32_t", "class", "compl", "const", 
        "constexpr", "const_cast", "continue", "decltype", "default", "delete", "do", "double", 
        "dynamic_cast", "else", "enum", "explicit", "export", "extern", "false", "float", "for", 
        "friend", "goto", "if", "inline", "int", "long", "mutable", "namespace", "new", 
        "noexcept", "not", "not_eq", "nullptr", "operator", "or", "or_eq", "private", "protected", 
        "public", "register", "reinterpret_cast", "return", "short", "signed", "sizeof", "static", 
        "static_assert", "static_cast", "struct", "switch", "template", "this", "thread_local", 
        "throw", "true", "try", "typedef", "typeid", "typename", "union", "unsigned", "using", 
        "virtual", "void", "volatile", "wchar_t", "while", "xor", "xor_eq"  // Добавлены  ключевые слова в массив
    };
    const int keywordCount = sizeof(keywords) / sizeof(keywords[0]);    //  Кол-во ключевых слов в массиве
    for (int i = 0; i < keywordCount; i++)  // Сравнение слова со словами из массива ключевых слов
    {
        if (strcmp(word, keywords[i]) == 0) 
        {
            return true;
        }
    }
    return false;
}
void Gets(char* s)    // Функция для обработки строки
{
    const int max = 256;    // Максимальная длина слова
    char word[max];
    char cleanedWord[max];
    char readyStr[max] = "\0";
    int index = 0;
    std::cout << "Идентификатор(ы): ";
    for (int i = 0; s[i] != '\0'; i++)  // Пробел для разделения слов
    {
        if (s[i] != ' ')    // Если текущий символ не пробел, добавляем его в слово
        {
            word[index++] = s[i];
        }
        else 
        {
            word[index] = '\0'; // Завершаем текущее слово
            if (index > 0)  // Если слово не пустое
            {
                cleanWord(word, cleanedWord);   // Очищаем слово
                if (!onlyNumbers(cleanedWord) && !startsWithNumbers(cleanedWord) && !keywords(cleanedWord)) // Проверяем слово на соответствие условиям
                {
                    lowerCase(cleanedWord); // Преобразуем в нижний регистр очищенное слово
                    strcat_s(readyStr, cleanedWord); // Записываем символы из cleanedWord в конец строки readyStr
                    strcat_s(readyStr, " ");    // Добавляем пробел в конец строки readyStr
                    //std::cout << cleanedWord << " ";    // Выводим очищенное слово
                }
            }
            index = 0;  // Сбрасываем индекс для следующего слова
        }
    }
    if (index > 0)  // Обрабатываем последнее слово, если оно есть
    {
        word[index] = '\0'; // Завершаем текущее слово
        cleanWord(word, cleanedWord);
        if (!onlyNumbers(cleanedWord) && !startsWithNumbers(cleanedWord) && !keywords(cleanedWord))
        {
            lowerCase(cleanedWord); // Преобразуем в нижний регистр очищенное слово
            strcat_s(readyStr, cleanedWord);    // Записываем символы из cleanedWord в конец строки readyStr
            //std::cout << cleanedWord << " ";    // Выводим очищенное слово
        }
    }
    std::cout << readyStr;
}
int main() 
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251); // Устанавливаем локаль для поддержки русских символов
    const int max = 256; // Максимальная длина слова
    char s[max];
    std::cout << "Введите предложение: "; // Ввод строки
    std::cin.getline(s, max); // Используем getline для ввода строки
    Gets(s); // Вызов функции обработки строки с введенной строкой
}
