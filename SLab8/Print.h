#pragma once
#include "Object.h"
#include <string>
#include <iostream>
#include <limits>
using namespace std;

class Print :
    public Object
{
public:
    Print(void);
    Print(string, string);
    Print(const Print&);
    virtual ~Print(void);
    void Show();
    void Input();
    string Get_name() override { return name; };
    string Get_author();
    void Set_name(string);
    void Set_author(string);
    Print& operator=(const Print&);
protected:
    string name;
    string author;
};

