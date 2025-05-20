#include "Triad.h"


Triad::Triad(void)	//����������� ��� ����������
{
	first = 0;
	second = 0;
	third = 0;
}

Triad::~Triad(void)	//����������
{

}

Triad::Triad(int F, int S, int T)	//����������� � �����������
{
	first = F;
	second = S;
	third = T;
}

Triad::Triad(const Triad& t)	//����������� �����������
{
	first = t.first;
	second = t.second;
	third = t.third;
}

//������������
void Triad::set_first(int F)
{
	first = F;
}
void Triad::set_second(int S)
{
	second = S;
}
void Triad::set_third(int T)
{
	third = T;
}

Triad& Triad::operator=(const Triad& t)	//���������� �������� ������������
{
	if (&t == this) return *this;
	first = t.first;
	second = t.second;
	third = t.third;
	return *this;
}
//���������� ���������� ���������
bool Triad::operator==(const Triad& t) const
{
	return (first == t.first && second == t.second && third == t.third);
}
bool Triad::operator!=(const Triad& t) const
{
	return (first != t.first || second != t.second || third != t.third);
}

istream& operator>>(istream& in, Triad& t)	//���������� ������� �����
{
	cout << "Enter first: "; in >> t.first;
	cout << "Enter second: "; in >> t.second;
	cout << "Enter third: "; in >> t.third;
	return in;
}

ostream& operator<<(ostream& out, const Triad& t)	//���������� ������� ������
{
	out << "\nFirst: " << t.first;
	out << "\nSecond: " << t.second;
	out << "\nThird: " << t.third;
	return out;
}

void Triad::Show()
{
	cout << "\nFirst: " << first;
	cout << "\nSecond: " << second;
	cout << "\nThird: " << third << "\n";
}