#include "F:/Labs C++/SLab11_task2/money.h"
#include <iostream>
#include <stack>
#include <vector>
using namespace std;

typedef stack<Money>St;
typedef vector<Money>Vec;

St make_stack(int n)
{
	St s;
	Money m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		s.push(m);
	}
	return s;
}

Vec copy_stack_to_vector(St s)
{
	Vec v;
	while (!s.empty())
	{
		v.push_back(s.top());
		s.pop();
	}
	return v;
}

St copy_vector_to_stack(Vec v)
{
	St s;
	for (int i = 0; i < v.size(); i++)
	{
		s.push(v[i]);
	}
	return s;
}

void print_stack(St& s)
{
	Vec v = copy_stack_to_vector(s);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	s = copy_vector_to_stack(v);
	cout << endl;
}

void push_max(St& s)
{
	Vec v = copy_stack_to_vector(s);
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

void remove_elem(St& s)
{
	Money value;
	cout << "Enter the value to remove : \n"; cin >> value;
	Vec v;
	while (!s.empty())
	{
		if (s.top() != value) v.push_back(s.top());
		s.pop();
	}
	s = copy_vector_to_stack(v);
}

void add_mean_all(St& s)
{
	Vec v = copy_stack_to_vector(s);
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

int main()
{
	Money m;
	St s;
	int n;
	cout << "N: ";
	cin >> n;
	s = make_stack(n);
	cout << "Stack: "; print_stack(s);
	push_max(s);
	cout << "push_max: "; print_stack(s);
	remove_elem(s);
	cout << "remove_elem: "; print_stack(s);
	add_mean_all(s);
	cout << "add_mean_all: "; print_stack(s);
}