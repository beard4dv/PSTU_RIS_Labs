#pragma once
#include "Print.h"

class Book :
    public Print
{
public:
    Book(void);
    Book(string, string, int, string);
    Book(const Book&);
    virtual ~Book(void);
    void Show();
    void Input();
    int Get_pages();
    string Get_pubHouse();
    void Set_pages(int);
    void Set_pubHouse(string);
    Book& operator=(const Book&);
protected:
    int pages;
    string pubHouse;
};

