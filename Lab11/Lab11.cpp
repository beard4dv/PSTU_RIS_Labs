#include <iostream>
#include <cstdio>

// Структура узла двунаправленного списка
struct Count
{
    int key;
    Count* prev;
    Count* next;
};

// Функция создания списка
Count* createList()
{
    return nullptr; // Пустой список
}

// Добавление элемента в конец списка
void addToEnd(Count*& head, int key)
{
    Count* newCount = new Count{ key, nullptr, nullptr };
    if (!head)
    {
        head = newCount;
    }
    else
    {
        Count* temp = head;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = newCount;
        newCount->prev = temp;
    }
}

// Функция печати списка
void printList(Count* head)
{
    if (!head)
    {
        std::cout << "Список пустой.\n";
        return;
    }
    Count* temp = head;
    while (temp)
    {
        std::cout << temp->key << " ";
        temp = temp->next;
    }
    std::cout << std::endl;
}

// Удаление K элементов перед элементом с заданным номером
void deleteBefore(Count*& head, int position, int K)
{
    if (!head || position <= 1 || K <= 0) return;

    Count* target = head;
    for (int i = 1; i < position && target; i++)
    {
        target = target->next;
    }
    if (!target) return;

    Count* temp = target->prev;
    for (int i = 0; i < K && temp; i++)
    {
        Count* toDelete = temp;
        temp = temp->prev;
        if (toDelete->prev) toDelete->prev->next = toDelete->next;
        if (toDelete->next) toDelete->next->prev = toDelete->prev;
        if (toDelete == head) head = toDelete->next;
        delete toDelete;
    }
}

// Добавление K элементов в конец списка
void addToEndInput(Count*& head, int K)
{
    for (int i = 0; i < K; i++)
    {
        int value;
        std::cout << "Введите значение для нового элемента: ";
        std::cin >> value;
        addToEnd(head, value);
    }
}

// Запись списка в файл
void createFile(Count* head)
{
    FILE* F1 = fopen("list.txt", "w");
    if (!F1)
    {
        std::cout << "Ошибка открытия файла для записи!\n";
        return;
    }
    Count* temp = head;
    while (temp)
    {
        fprintf(F1, "%d ", temp->key);
        temp = temp->next;
    }
    fclose(F1);
}

// Уничтожение списка
void destroyList(Count*& head)
{
    while (head)
    {
        Count* temp = head;
        head = head->next;
        delete temp;
    }
}

// Восстановление списка из файла
void restoreFromFile(Count*& head)
{
    FILE* F1 = fopen("list.txt", "r");
    if (!F1)
    {
        std::cout << "Ошибка открытия файла для чтения!\n";
        return;
    }
    destroyList(head); // Очистка текущего списка
    int value;
    while (fscanf(F1, "%d", &value) == 1)
    {
        addToEnd(head, value);
    }
    fclose(F1);
}

int main()
{
    setlocale(LC_ALL, "Russian");
    Count* list = createList();

    // Создание списка
    int n;
    std::cout << "Введите количество элементов в списке: ";
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int value;
        std::cout << "Введите значение элемента " << i + 1 << ": ";
        std::cin >> value;
        addToEnd(list, value);
    }
    std::cout << "Список создан: ";
    printList(list);

    // Удаление K элементов перед заданным элементом
    int position, K;
    std::cout << "Введите номер элемента, перед которым нужно удалить K элементов: ";
    std::cin >> position;
    std::cout << "Введите количество элементов для удаления: ";
    std::cin >> K;
    deleteBefore(list, position, K);
    std::cout << "Список после удаления: ";
    printList(list);

    // Добавление K элементов в конец списка
    addToEndInput(list, K);
    std::cout << "Список после добавления: ";
    printList(list);

    // Запись списка в файл
    createFile(list);
    std::cout << "Список записан в файл.\n";

    // Уничтожение списка
    destroyList(list);
    std::cout << "Список уничтожен.\n";
    printList(list);

    // Восстановление списка из файла
    restoreFromFile(list);
    std::cout << "Список восстановлен из файла: ";
    printList(list);

    // Уничтожение списка
    destroyList(list);
    std::cout << "Список окончательно уничтожен.\n";
}