#include <iostream>
#include <string>
#include "employee.h"
using namespace std;

Employee make_employee()
{
	string n;
	string p;
	double s;
	cout << "Enter full name: "; getline(cin,n); cout << "\n";
	cout << "Enter position: "; cin >> p; cout << "\n";
	cout << "Enter salary: "; cin >> s; cout << "\n";
	Employee e(n, p, s);
	return e;
}

void print_employee(Employee e)
{
	e.show();
}

int main()
{
	Employee e1;
	e1.show();

	Employee e2("Ivanov Ivan Ivanovich", "Driver", 30000);
	e2.show();

	Employee e3 = e2;
	e3.set_name("Divanov Divan Divanovich");
	e3.set_position("Divan");
	e3.set_salary(10000);
	cout << "e2.get_name: " << e2.get_name() << "\n";
	cout << "e2.position: " << e2.get_position() << "\n";
	cout << "e2.salary: " << e2.get_salary() << "\n";

	print_employee(e3);

	e1 = make_employee();
	e1.show();
}