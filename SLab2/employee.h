#include <iostream>
#include <string>
using namespace std;

class Employee
{
	string name;
	string position;
	double salary;
public:
	Employee();
	Employee(string, string, double);
	Employee(const Employee&);
	~Employee();
	string get_name();
	void set_name(string);
	string get_position();
	void set_position(string);
	double get_salary();
	void set_salary(double);
	void show();
};