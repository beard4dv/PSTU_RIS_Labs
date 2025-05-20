#include "Set1.h"
#include "Set3.h"

int main()
{
	cout << "===Implementation option #3===\n";
	try
	{
		Set3 x3(6);
		cout << "Enter set x:" << "\n"; cin >> x3;
	}
	catch (Error &e)
	{
		e.what();
	}
	try
	{
		int size3;
		cout << "Enter set size: "; cin >> size3;
		Set3 y3(size3);
		cout << "Enter set y:"; cin >> y3;
		cout << "\nSet y: " << y3 << "\n";
		int pos3;
		cout << "Enter set position[0-" << size3-1 << "]: "; cin >> pos3;
		cout << y3[pos3] << "\n";
		Iterator3 i = y3.first(); 
		cout << "Shift value: "; int value3; cin >> value3;
		i += value3;
		cout << "i += 2: " << *i << "\n";
	}
	catch (Error &e)
	{
		e.what();
	}
	cout << "===Implementation option #1===\n";
	try
	{
		Set x(6);
		cout << "Enter set x:" << "\n"; cin >> x;
	}
	catch (int num)
	{
		cout << "Error #" << num << "\n";
	}
	try
	{
		int size;
		cout << "Enter set size: "; cin >> size;
		Set y(size);
		cout << "Enter set y:"; cin >> y;
		cout << "\nSet y: " << y << "\n";
		int pos;
		cout << "Enter set position[0-" << size - 1 << "]: "; cin >> pos;
		cout << y[pos] << "\n";
		Iterator i = y.first();
		cout << "Shift value: "; int value; cin >> value;
		i += value;
		cout << "i += 2: " << *i << "\n";
	}
	catch (int num)
	{
		cout << "Error code " << num << "\n";
	}
}