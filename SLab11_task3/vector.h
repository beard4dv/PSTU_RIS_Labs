#pragma once
#include <iostream>
#include <vector>
using namespace std;

template<class T>
class Vector
{
	vector <T> v;
	int len;
public:
	Vector(void);
	Vector(int n);
	void print_vector();
	~Vector(void);
	void push_back_max();
	void remove_elem(const T& value);
	void add_mean_all();
};

template <class T>
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::~Vector(void) {}

template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		v.push_back(a);
	}
	len = v.size();
}

template <class T>
void Vector<T>::print_vector()
{
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	cout << "\n";
}

template<class T>
void Vector<T>::push_back_max()
{
	T max;
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] > max) max = v[i];
	}
	v.push_back(max);
}

template<class T>
void Vector<T>::remove_elem(const T& value)
{
	for (int i = 0; i < v.size(); i++)
	{
		if (v[i] == value) v.erase(v.begin() + i);
	}
}

template<class T>
void Vector<T>::add_mean_all()
{
	T sum;
	for (int i = 0; i < v.size(); i++)
	{
		sum = sum + v[i];
	}
	cout << sum << "\n";
	T mean = sum / v.size();
	cout << mean << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + mean;
	}
}