#include "Set3.h"

Set3::Set3(int s, int k)
{
	if (s > MAX_SIZE3) throw MaxSizeError();
	if (s <= 0) throw EmptySizeError();
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

Set3::Set3(const Set3& s)
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

Set3::~Set3()
{
	delete[] data;
	data = nullptr;
}

Set3& Set3::operator=(const Set3& s)
{
	if (this == &s) return *this;
	size = s.size;
	if (data != nullptr) delete[] data;
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

int& Set3::operator[](int index)
{
	if (index < 0) throw IndexError1();
	if (index >= size) throw IndexError2();
	return data[index];
}

bool Set3::operator!=(const Set3& s) const
{
	if (size != s.size) return true;
	for (int i = 0; i < size; i++)
	{
		if (data[i] != s.data[i]) return true;
	}
	return false;
}

bool Set3::operator<(int number) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == number) return true;
	}
	return false;
}

ostream& operator<<(ostream& out, const Set3& s)
{
	for (int i = 0; i < s.size; i++)
	{
		out << s.data[i] << " ";
	}
	return out;
}

istream& operator>>(istream& in, Set3& s)
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