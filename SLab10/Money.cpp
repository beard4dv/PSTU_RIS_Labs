#include <iostream>
#include "Money.h"
using namespace std;

void Money::recount()
{
	if (kop >= 100) {
		rub += kop / 100;
		kop %= 100;
	}
	else if (kop < 0) {
		rub -= (abs(kop) / 100 + 1);
		kop = 100 - abs(kop) % 100;
	}
}

Money& Money::operator=(const Money& m)
{
	if (this != &m)
	{
		rub = m.rub;
		kop = m.kop;
	}
	return *this;
}

Money Money::operator-(float value)
{
	long r = static_cast<long>(value);
	int k = static_cast<int>((value - r) * 100);
	return Money(rub - r, kop - k);
}

bool Money::operator==(const Money& m)
{
	return rub == m.rub && kop == m.kop;
}

bool Money::operator!=(const Money& m)
{
	return rub != m.rub || kop != m.kop;
}

istream& operator>>(istream& in, Money& m)
{
	bool fail = false;
	cout << "rub: "; in >> m.rub;
	do
	{
		cout << "kop(0-99): "; in >> m.kop;
		if (m.kop > 99 || m.kop < 0)
		{
			cout << "Error! Enter correct value.\n";
			fail = true;
		}
		else fail = false;
	} while (fail);
	return in;
}

ostream& operator<<(ostream& out, const Money& m)
{
	return (out << m.rub << "," << m.kop);
}

fstream& operator>>(fstream& fin, Money& m)
{
	fin >> m.rub;
	fin >> m.kop;
	return fin;
}
fstream& operator<<(fstream& fout, const Money& m)
{
	fout << m.rub << "\n" << m.kop << "\n";
	return fout;
}