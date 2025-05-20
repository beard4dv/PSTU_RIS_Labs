#include "Container.h"
#include "F:\Labs C++\SLab11_task2\money.h"

int main()
{
	int n;
	cout << "Enter set size: "; cin >> n;
	Container<Money> s(n);
	cout << "Set: "; s.print_set();
	Money value; cout << "Enter the value to remove: \n"; cin >> value;
	s.remove_elem(value);
	cout << "remove_elem: "; s.print_set();
	s.add_mean_all();
	cout << "add_mean_all: "; s.print_set();
}