#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Vector
{
public:
	Vector(void);
	Vector(int);
public:
	~Vector(void);
	void Add(Object*); // добавление элемента в вектор
	friend ostream& operator<<(ostream& out, const Vector&);
private:
	Object** beg;	//указатель на первый элемент
	int size;	//размер
	int cur;	//текущая позиция
};