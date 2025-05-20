#pragma once
#include <iostream>
#include "Error.h"
using namespace std;

const int MAX_SIZE3 = 5;

class Iterator3
{
	friend class Set3;
public:
	Iterator3() { elem = nullptr; start = nullptr; size = 0; }
	Iterator3(const Iterator3& it) {
		elem = it.elem;
		start = it.start;
		size = it.size;
	}

	bool operator==(const Iterator3& it) { return elem == it.elem; }
	bool operator!=(const Iterator3& it) { return elem != it.elem; }
	void operator++() { ++elem; }
	void operator--() { --elem; }
	void operator+=(int n) 
	{
		int index = elem - start;
		if (index + n < 0 || index + n >= size) throw IndexError2();
		elem += n;
	}
	int& operator*() const { return *elem; }

private:
	int* elem;
	int* start;
	int size;
};

class Set3
{
public:
	Set3(int s, int k = 0);
	Set3(const Set3& s);
	~Set3();
	Set3& operator=(const Set3& s);
	int& operator[](int index);
	bool operator!=(const Set3& s) const;
	bool operator<(int number) const;
	friend ostream& operator<<(ostream& out, const Set3& s);
	friend istream& operator>>(istream& in, Set3& s);
	Iterator3 first() { return beg; }
	Iterator3 last() { return end; }
	int Get_size() { return size; }
protected:
	int size;
	int* data;
	int count;
	Iterator3 beg;
	Iterator3 end;
};

