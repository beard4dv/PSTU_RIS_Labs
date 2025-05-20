#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 5;

class Set;

class Iterator
{
	friend class Set;
public:
	Iterator() { elem = nullptr; start = nullptr; size = 0; }
	Iterator(const Iterator& it) 
	{
		elem = it.elem;
		start = it.start;
		size = it.size;
	}
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	void operator++() { ++elem; };
	void operator--() { --elem; }
	void operator+=(int n) 
	{
		int index = elem - start;
		if (index + n < 0 || index + n >= size) throw 5;
		elem += n;
	}
	int& operator *() const { return*elem; }
private:
	int* elem;
	int* start;
	int size;
};

class Set
{
public:
	Set(int s, int k = 0);
	Set(const Set& s);
	~Set();
	Set& operator=(const Set& s);
	int& operator[](int index);
	bool operator!=(const Set& s) const;
	bool operator<(int number) const;
	friend ostream& operator<<(ostream& out, const Set& s);
	friend istream& operator>>(istream& in, Set& s);
	Iterator first() { return beg; }
	Iterator last() { return end; }
	int Get_size() { return size; }
protected:
	int size;
	int* data;
	int count;
	Iterator beg;
	Iterator end;
};
