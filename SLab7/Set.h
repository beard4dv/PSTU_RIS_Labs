#pragma once
#include <iostream>
using namespace std;

template <class T>
class Set
{
public:
	Set(int s, T k);
	Set(const Set<T>& s);
	~Set();
	Set& operator=(const Set<T>& s);
	T& operator[](int index);
	bool operator!=(const Set<T>& s) const;
	bool operator<(const T& number) const;
	friend ostream& operator<<<>(ostream& out, const Set<T>& s);
	friend istream& operator>><>(istream& in, Set<T>& s);
private:
	int size;
	T* data;
	int count;
};

template <class T>
Set<T>::Set(int s, T k)
{
	size = s;
	data = new T[size];
	for (int i = 0; i < size; i++)
	{
		data[i] = k;
	}
}

template <class T>
Set<T>::Set(const Set& s)
{
	size = s.size;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = s.data[i];
}

template <class T>
Set<T>::~Set()
{
	delete[]data;
	data = 0;
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& s)
{
	if (this == &s)return *this;
	size = s.size;
	if (data != 0) delete[]data;
	data = new T[size];
	for (int i = 0; i < size; i++)
		data[i] = s.data[i];
	return *this;
}

template <class T>
T& Set<T>::operator[](int index)
{
	if (index < size) return data[index];
	else cout << "\nError! Index>size";
}

template <class T>
bool Set<T>::operator!=(const Set<T>& s) const
{
	if (size != s.size) return true;
	for (int i = 0; i < size; i++)
	{
		if (data[i] != s.data[i]) return true;
	}
	return false;
}

template <class T>
bool Set<T>::operator<(const T& number) const
{
	for (int i = 0; i < size; i++)
	{
		if (data[i] == number) return true;
	}
	return false;
}

template <class T>
ostream& operator<< (ostream& out, const Set<T>& s)
{
	for (int i = 0; i < s.size; i++)
	{
		out << s.data[i] << " ";
	}
	return out;
}

template <class T>
istream& operator>> (istream& in, Set<T>& s)
{
	T temp;
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
