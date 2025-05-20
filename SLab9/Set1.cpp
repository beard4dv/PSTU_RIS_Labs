#include "Set1.h"

Set::Set(int s, int k)
{
	if (s > MAX_SIZE) throw 1;
	if (s <= 0) throw 2;
	size = s;
	data = new int[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
	beg.elem = &data[0];
	beg.start = data;
	beg.size = size;

	end.elem = &data[size];
	end.start = data;
	end.size = size;
}

Set::Set(const Set& s)
{
	size = s.size;
	data = new int[size];
	for (int i = 0; i < size; i++)
		data[i] = s.data[i];
	beg.elem = data;
	beg.start = data;
	beg.size = size;
	end.elem = data + size;
	end.start = data;
	end.size = size;
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
	beg.elem = data;
	beg.start = data;
	beg.size = size;
	end.elem = data + size;
	end.start = data;
	end.size = size;
	return *this;
}

int& Set::operator[](int index)
{
	if (index < 0)throw 3;
	if (index >= size) throw 4;
	return data[index];

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