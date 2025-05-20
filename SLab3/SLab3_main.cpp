#include <iostream>
#include "money.h"
using namespace std;

int main()
{
	Money a;
	Money b;
	Money c(10, 50);
	Money d(10, 50);
	cin >> a;
	cout << "a = " << a << "\n";
	b = a - 1.90;
	cout << "(b = a - 1.90) b = " << b << "\n";
	bool check1 = c == d; cout << check1 << "\n";
	bool check2 = c != b; cout << check2 << "\n";
}