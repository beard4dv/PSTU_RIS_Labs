#include "Set.h"

Set::Set(int s, int k)
{
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
	beg.elem = &data[0];
	end.elem = &data[size];
}

Set::Set(const Set& s)
{
	size = s.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = s.data[i];
	beg = s.beg;
	end = s.end;
}

Set::~Set()
{
	delete[]data;
	data = 0;
}

Set& Set::operator=(const Set& s)
{
	if (this == &s)return *this;
	size = s.size;
	if (data != 0) delete[]data;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = s.data[i];
	beg = s.beg;
	end = s.end;
	return *this;
}

int& Set::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}

bool Set::operator!=(const Set& s) const
{
	if (size != s.size) return true;
	for (int i = 0; i < size; i++)
	{
		if (data[i] != s.data[i]) return true;
	}
	return false;
}

bool Set::operator<(int number) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == number) return true;
	}
	return false;
}


ostream& operator<<(ostream& out, const Set& s)
{
	for (int i = 0; i < s.size; i++)
	{
		out << s.data[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, Set& s)
{
	int temp;
	s.count = 0;
	for (int i = 0; i < s.size; i++) {
		in >> temp;
		if (!(s < temp)) {
			s.data[s.count++] = temp;
		}
		else {
			cout << "Number " << temp << " is in the set.\n";
			i--;
		}
	}
	return in;
}