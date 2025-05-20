#pragma once
#include <iostream>
using namespace std;

class Money
{
public:
	Money() { rub = 0; kop = 0; };
	Money(long r, int k) { rub = r; kop = k; recount(); };
	Money(const Money& m) { rub = m.rub; kop = m.kop; };
	virtual ~Money() {};
	Money& operator=(const Money&);
	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);
	bool operator!=(const Money& m);
	bool operator==(const Money& m);
private:
	void recount();
	long rub;
	int kop;
};