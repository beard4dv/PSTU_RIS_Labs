#include "Triad.h"
#include "Time.h"
#include "Object.h"
#include "Vector.h"
#include <iostream>
using namespace std;

int main()
{
	//Triad a;
	//cin >> a;
	//cout << a << "\n";
	//Object* p = &a;
	//p->Show();
	//Time b;
	//cin >> b;
	//cout << b << "\n";
	//p = &b;
	//p->Show();
	Vector v(5);
	Triad a;
	cin >> a;
	Time b;
	cin >> b;
	Object* p = &a;
	v.Add(p);
	p = &b;
	v.Add(p);
	cout << v;
}