#include "Set.h"

int main()
{
	Set a(5);
	cout << "a: " << a << "\n";
	cin >> a;
	cout << "a: " << a << "\n";
	a[2] = 100;
	cout << "a: " << a << "\n";
	Set b(10);
	cout << "b: " << b << "\n";
	b = a;
	cout << "b: " << b << "\n";
	Set c(5);
	cin >> c;
	cout << "c: " << c << "\n";
	cout << "\n\na != c: " << (a != c ? "true" : "false");
	cout << "\n\na < 5: " << (a < 5 ? "true" : "false") << "\n";
	cout << "a.first: " << *(a.first()) << endl;22
	Iterator i = a.first();
	i += 2;
	cout << "i += 2: " << *i << endl;
	for (i = a.first(); i != a.last(); ++i) cout << *i << " ";
}