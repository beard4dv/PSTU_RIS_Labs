#pragma once
#include "Object.h"
#include <iostream>
using namespace std;

class Triad:
	public Object
{
public:
	Triad(void);	//����������� ��� ����������

public:
	virtual ~Triad(void);	//����������
	void Show();
	Triad(int, int, int);	//����������� � �����������
	Triad(const Triad&);	//����������� �����������
	//���������
	int get_first() const { return first; }
	int get_second() const { return second; }
	int get_third() const { return third; }
	//������������
	void set_first(int);
	void set_second(int);
	void set_third(int);
	//���������� �������� ������������
	Triad& operator=(const Triad&);
	//���������� ���������� ���������
	bool operator==(const Triad& t) const;
	bool operator!=(const Triad& t) const;
	//���������� ���������-������� �����-������
	friend istream& operator>>(istream& in, Triad& t);
	friend ostream& operator<<(ostream& out, const Triad& t);

protected:
	int first;
	int second;
	int third;

};