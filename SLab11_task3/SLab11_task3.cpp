#include <iostream>
#include "vector.h"
#include "F:/Labs C++/SLab11_task2/money.h"

int main()
{
	Vector<Money>vec(5);
	cout << "vector: "; vec.print_vector();
	vec.push_back_max();
	cout << "push_back_max: "; vec.print_vector();
	Money value;
	cout << "Enter the value to remove: \n"; cin >> value;
	vec.remove_elem(value);
	cout << "remove_elem: "; vec.print_vector();
	vec.add_mean_all();
	cout << "add_mean_all: "; vec.print_vector();
}
