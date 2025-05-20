#pragma once
#include <set>
#include <iostream>

using namespace std;

template<class T>
class Container
{
	set<T, less<T>> s;
	int len;
public:
	Container(void);
	Container(int n);
	~Container(void);
	void print_set();
	void remove_elem(T);
	void add_mean_all();
};

template <class T>
Container<T>::Container()
{
	len = 0;
}

template <class T>
Container<T>::~Container(void) {}

template<class T>
Container<T>::Container(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a[" << i << "]: \n";
		cin >> a;
		s.insert(a);
	}
	len = s.size();
}

template<class T>
void Container<T>::print_set()
{
	for (auto it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";
}

template<class T>
void Container<T>::remove_elem(T value)
{
	s.erase(value);
}
template<class T>
void Container<T>::add_mean_all()
{
	T sum;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		sum = sum + *it;
	}
	T mean = sum / s.size();
	cout << "mean: " << mean << "\n";
	set<T> tempSet;
	for (auto it = s.begin(); it != s.end(); it++)
	{
		tempSet.insert(*it + mean);
	}
	s = tempSet;
}