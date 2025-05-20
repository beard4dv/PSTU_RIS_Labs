#include <iostream>
#include <string>
#include "employee.h"
using namespace std;
//����������� ��� ����������
Employee::Employee()
{
	name = "";
	position = "";
	salary = 0;
	cout << "Constructor without parameters for object " << this << endl;
}
//����������� � �����������
Employee::Employee(string N, string P, double S)
{
	name = N;
	position = P;
	salary = S;
	cout << "Constructor with parameters for object " << this << endl;
}
//����������� �����������
Employee::Employee(const Employee& e)
{
	name = e.name;
	position = e.position;
	salary = e.salary;
	cout << "Copy constructor for object " << this << endl;
}
//����������
Employee::~Employee()
{
	cout << "Destructor for object " << this << endl;
}
//���������
string Employee::get_name()
{
	return name;
}
string Employee::get_position()
{
	return position;
}
double Employee::get_salary()
{
	return salary;
}
//������������
void Employee::set_name(string N)
{
	name = N;
}
void Employee::set_position(string P)
{
	position = P;
}
void Employee::set_salary(double S)
{
	salary = S;
}
void Employee::show()
{
	cout << "Full name: " << name << endl;
	cout << "Position: " << position << endl;
	cout << "Salary: " << salary << endl;
}