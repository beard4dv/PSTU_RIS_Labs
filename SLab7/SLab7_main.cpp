#include <iostream>
#include "Set.h"
#include "Money.h"
using namespace std;

int main()
{
	Set<float>check1(5, 0.1f);
	cout << "check1(float): " << check1 << "\n";
	Set<double>check2(5, 0.2);
	cout << "check2(double): " << check2 << "\n";
	Set<int>a(5, 0);
	cin >> a;
	cout << "a: " << a << "\n";
	Set<int>b(10, 1);
	cout << "b: " << b << "\n";
	b = a;
	cout << "b: " << b << "\n";
	cout << "b[2]:" << b[2];
	cout << "\n\na != b: " << (a != b ? "true" : "false");
	cout << "\n\na < 5: " << (a < 5 ? "true" : "false") << "\n";
	Money m;
	cin >> m;
	cout << "m: " << m << "\n";
	Set<Money>ma(5, m);
	cin >> ma;
	cout << "ma: " << ma << "\n";
	Set<Money>mb(10, m);
	cout << "mb: " << mb << "\n";
	mb = ma;
	cout << "mb: " << mb << "\n";
	cout << "ma[2]:" << ma[2];
	cout << "\n\nma != mb: " << (ma != mb ? "true" : "false");
}