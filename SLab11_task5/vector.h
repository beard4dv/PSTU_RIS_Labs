#pragma once
#include <iostream>
#include <stack>
#include <vector>
#include "F:/Labs C++/SLab11_task2/money.h"
using namespace std;

template<class T>
class Vector
{
	stack <T> s;
	int len;
public:
	Vector();
	Vector(int n);
	Vector(const Vector<T>&);
	void print_stack();
	void push_max();
	void remove_elem();
	void add_mean_all();
};

template <class T>
vector<T> copy_stack_to_vector(stack<T> s)
{
	vector<T> v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

template <class T>
stack<T> copy_vector_to_stack(vector<T> v)
{
	stack<T> s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

template <class T>
Vector<T>::Vector()
{
	len = 0;
}

template <class T>
Vector<T>::Vector(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		s.push(a);
	}
	len = s.size();
}

template <class T>
Vector<T>::Vector(const Vector<T>& Vec)
{
	len = Vec.len;
	vector<T> v = copy_stack_to_vector(Vec.s);
	s = copy_vector_to_stack(v);
}

template <class T>
void Vector<T>::print_stack()
{
	vector<T> v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
	s = copy_vector_to_stack(v);
}

template <class T>
void Vector<T>::push_max()
{
	vector<T> v = copy_stack_to_vector(s);
	Money max = s.top();
	s.pop();
	while (!s.empty())
	{
		if (s.top() > max) max = s.top();
		s.pop();
	}
	s = copy_vector_to_stack(v);
	s.push(max);
}

template <class T>
void Vector<T>::remove_elem()
{
	Money value;
	cout << "Enter the value to remove : \n"; cin >> value;
	vector<T> v;
	while (!s.empty())
	{
		if (s.top() != value) v.push_back(s.top());
		s.pop();
	}
	s = copy_vector_to_stack(v);
}

template <class T>
void Vector<T>::add_mean_all()
{
	vector<T> v = copy_stack_to_vector(s);
	Money sum;
	while (!s.empty())
	{
		sum = sum + s.top();
		s.pop();
	}
	cout << sum << "\n";
	Money mean = sum / v.size();
	cout << mean << "\n";
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] + mean;
	}
	s = copy_vector_to_stack(v);
}