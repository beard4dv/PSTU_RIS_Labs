#include "List.h"
#include <cstdint>

List::List() 
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}

List::~List() 
{
    Node* curr = head;
    while (curr != nullptr) 
    {
        if (reinterpret_cast<uintptr_t>(curr) == 0xCDCDCDCDCDCDCDCD)
        {
            std::cout << "\nSkip DEBUG memory error (0xCDCDCDCDCDCDCDCD).\n";
            break;
        }
        Node* nextNode = curr->next;
        delete curr;
        curr = nextNode;
    }
}

void List::pushback(Object* obj) 
{
    Node* newNode = new Node;
    newNode->data = obj;
    if (head == nullptr) {
        head = newNode;
        tail = newNode;
        size++;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        size++;
    }
}

void List::Add()
{
    Object* p;
    cout << "1. Print" << "\n";
    cout << "2. Book" << "\n" << "Select: ";
    int y;
    /*cin >> y;*/
    while (true)
    {
        cin >> y;
        if (cin.fail())
        {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Input error. Please enter int number: ";
        }
        else if (y == 1 || y == 2)
        {
            break;
        }
        else
        {
            cout << "Select 1 or 2: ";
        }
    }
    cin.ignore();
    if (y == 1)
    {
        Print* a = new(Print);
        a->Input();
        p = a;
        pushback(p);
    }
    else {
        if (y == 2) {
            Book* b = new(Book);
            b->Input();
            p = b;
            pushback(p);
        }
    }
}

void List::Del()
{
    if (head != nullptr) 
    {
        Node* curr = tail;
        tail = curr->prev;
        delete curr;
        if (tail) 
        {
            tail->next = nullptr;
        }
        else {
            head = nullptr;
        }
        size--;
    }
}

void List::Show() 
{
    if (size == 0) 
    {
        cout << "Empty" << endl;
    }
    Node* node = head;
    Object* p = head->data;
    cout << "Size: " << this->size << "\n";
    while (node != nullptr) 
    {
        if (reinterpret_cast<uintptr_t>(node) == 0xCDCDCDCDCDCDCDCD)
        {
            std::cout << "\nSkip DEBUG memory error (0xCDCDCDCDCDCDCDCD).\n";
            break;
        }
        p = node->data;
        p->Show();
        node = node->next;
        cout << endl;
    }
}

int List::operator()() 
{
    return size;
}

void List::Get_elname(int k)
{
    if (k < 0 || k >= size) {
        cout << "Error: Index out of range!" << endl;
        return;
    }
    Node* curr = head;
    int count = 0;
    while (curr != nullptr) {
        if (count == k) {
            cout << "Element name: " << curr->data->Get_name() << endl;
            return;
        }
        curr = curr->next;
        count++;
    }
}