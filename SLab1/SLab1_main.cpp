#include <iostream>
#include "fraction.h"
using namespace std;

double mainInput() {
	double value;
	while (true) {
		cin >> value;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Error! Enter correct value: ";
		}
		else {
			return value;
		}
	}
}

fraction make_fraction(double F, double S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

void main()
{
	fraction A;
	fraction B;
	double x1, y1;
	cout << "Enter coordinates x1: "; x1 = mainInput();
	cout << "Enter coordinates y1: "; y1 = mainInput();	
	A.Init(3,4);
	B.Read();
	cout << "\n";
	cout << "Coordinates A"; A.Show(); cout << "\n";
	cout << "Coordinates B"; B.Show();
	cout << "\nCoordinates x1 = " << x1;
	cout << "\nCoordinates y1 = " << y1;
	cout<< "\nA.Distance of points = " << A.Distance(x1, y1);
	cout << "\nB.Distance of points = " << B.Distance(x1, y1);
	cout << "\n";
	//укзатели
	fraction* X = new fraction;
	X->Init(3, 4);
	cout << "\nCoordinates X"; X->Show();
	cout << "\nX.Distance of points = " << X->Distance(x1, y1);
	cout << "\n\n";
	//массивы
	fraction mas[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "mas#" << i << "\n";
		mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "\nmas#" << i; mas[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "\nmas#"<< i << ".Distance of points = " << mas[i].Distance(x1, y1);
	}
	cout << "\n\n";
	//динамические массивы
	fraction* d_mas = new fraction[3];
	for (int i = 0; i < 3; i++)
	{
		cout << "d_mas#" << i << "\n";
		d_mas[i].Read();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "\nd_mas#" << i; d_mas[i].Show();
	}
	for (int i = 0; i < 3; i++)
	{
		cout << "\nd_mas#" << i << ".Distance of points = " << d_mas[i].Distance(x1, y1);
	}
	double x, y;
	cout << "\nEnter coordinates x: "; x = mainInput();
	cout << "Enter coordinates y: "; y = mainInput();
	fraction F = make_fraction(x, y);
	cout << "Coordinates F"; F.Show();
}