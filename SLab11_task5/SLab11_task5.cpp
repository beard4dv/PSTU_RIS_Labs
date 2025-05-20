#include "vector.h"

int main()
{
	Vector<Money>v(3);
	cout << "Stack: "; v.print_stack();
	v.push_max();
	cout << "push_max: "; v.print_stack();
	v.remove_elem();
	cout << "remove_elem: "; v.print_stack();
	v.add_mean_all();
	cout << "add_mean_all: "; v.print_stack();
}