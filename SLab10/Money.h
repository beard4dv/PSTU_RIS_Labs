#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Money
{
	long rub;
	int kop;
private:
	void recount();
public:
	Money() { rub = 0; kop = 0; };
	Money(long r, int k) { rub = r; kop = k; recount(); };
	Money(const Money& m) { rub = m.rub; kop = m.kop; };
	~Money() {};
	long get_rub() { return rub; }
	int get_kop() { return kop; }
	void set_rub(long r) { rub = r; }
	void set_kop(int k) { kop = k; }
	//перегруженные операции
	Money& operator=(const Money&);
	Money operator-(float value);
	bool operator==(const Money& m);
	bool operator!=(const Money& m);
	//глобальные функции ввода-вывода
	friend istream& operator>>(istream& in, Money& m);
	friend ostream& operator<<(ostream& out, const Money& m);
	friend fstream& operator>>(fstream& fin, Money& m);
	friend fstream& operator <<(fstream& fout, const Money& m);
};