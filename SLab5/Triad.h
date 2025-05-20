#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Triad:
	public Object
{
public:
	Triad(void);	//конструктор без параметров

public:
	virtual ~Triad(void);	//деструктор
	void Show();
	Triad(int, int, int);	//конструткор с параметрами
	Triad(const Triad&);	//конструткор копирования
	//селекторы
	int get_first() const { return first; }
	int get_second() const { return second; }
	int get_third() const { return third; }
	//модификаторы
	void set_first(int);
	void set_second(int);
	void set_third(int);
	//перегрузка операции присваивания
	Triad& operator=(const Triad&);
	//перегрузка операторов сравнения
	bool operator==(const Triad& t) const;
	bool operator!=(const Triad& t) const;
	//глобальные операторы-функции ввода-вывода
	friend istream& operator>>(istream& in, Triad& t);
	friend ostream& operator<<(ostream& out, const Triad& t);

protected:
	int first;
	int second;
	int third;

};