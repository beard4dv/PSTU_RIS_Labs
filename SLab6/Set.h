#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class Set;
public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }
	bool operator==(const Iterator& it) { return elem == it.elem; }
	bool operator!=(const Iterator& it) { return elem != it.elem; };
	void operator++() { ++elem; };
	void operator--() { --elem; }
	void operator+=(int n) { elem += n; }
	int& operator *() const { return*elem; }
private:
	int* elem;
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
private:
	int size;
	int* data;
	int count;
	Iterator beg;
	Iterator end;
};