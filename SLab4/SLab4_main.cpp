#include "Triad.h"
#include "Time.h"
#include <iostream>
using namespace std;

void f1(Triad& t)
{
	t.set_first(10);
	cout << "\n###base class after set OUT###" << t;
}
Triad f2()
{
	Time t(1, 10, 30);
	return t;
}

int main()
{
	Triad a;
	cout << "###Triad a IN###\n"; cin >> a;
	cout << "###Triad a OUT##" << a;
	Triad b(1, 2, 3);
	cout << "\n###Triad b OUT###"; cout << b;
	Triad c;
	c = a;
	cout << "\n###Triad c OUT###"; cout << c;
	cout << "\n\na==c: " << (a == c ? "true" : "false");
	cout << "\n\nb!=c: " << (b != c ? "true" : "false") << "\n\n";
	Time t1;
	cout << "###Time t1 IN###\n"; cin >> t1;
	cout << "###Time t1 OUT###" << t1;
	Time t2(0, 30, 10);
	cout << "\n###Time t2 OUT###" << t2;
	Time t3(t1);
	cout << "\n###Time t3 OUT###" << t3;
	cout << "\n\nt1 == t3: " << (t1 == t3 ? "true" : "false");
	cout << "\n\nt2 != t3: " << (t2 != t3 ? "true" : "false");
	cout << "\n\nt1 < t2: " << (t1 < t2 ? "true" : "false");
	cout << "\n\nt1 <= t2: " << (t1 <= t2 ? "true" : "false");
	cout << "\n\nt1 > t2: " << (t1 > t2 ? "true" : "false");
	cout << "\n\nt1 >= t2: " << (t1 > t2 ? "true" : "false") << "\n\n";
	
	f1(t1);
	a = f2();
	cout << "\n###base class like result OUT###" << a;
}