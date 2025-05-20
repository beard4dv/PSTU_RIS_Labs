#include <iostream>
#include <cmath>
#include "fraction.h"
using namespace std;

double input() {
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

void fraction::Init(double F, double S)
{
	first = F; second = S;
}
void fraction::Read()
{
    cout << "Enter coordinates first: "; first = input();
	cout << "Enter coordinates second: "; second = input();
}
void fraction::Show()
{
	cout << "\nCoordinates first = " << first;
	cout << "\nCoordinates second = " << second;
}
double fraction::Distance(double F, double S)
{
	return sqrt(pow(F - first, 2) + pow(S - second, 2));
}