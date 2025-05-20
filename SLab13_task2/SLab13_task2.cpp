#include "F:\Labs C++\SLab11_task2\money.h"
#include <iostream>
#include <stack>
#include <deque>
#include <algorithm>

typedef stack<Money>St;
typedef deque<Money>Deq;
Money s1;

struct Comp_less
{
public:
	bool operator() (Money m1, Money m2)
	{
		if (m1 > m2) return true;
		else return false;
	}
};

struct Equal_s
{
	bool operator()(Money m)
	{
		return m == s1;
	}
};

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

Deq copy_stack_to_deque(St s)
{
	Deq d;
	while (!s.empty())
	{
		d.push_back(s.top());
		s.pop();
	}
	return d;
}

St copy_deque_to_stack(Deq d)
{
	St s;
	for (int i = 0; i < d.size(); i++)
	{
		s.push(d[i]);
	}
	return s;
}

void print_stack(St& s)
{
	Deq d = copy_stack_to_deque(s);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	s = copy_deque_to_stack(d);
	cout << endl;
}

void push_max(St& s)
{
	Deq d = copy_stack_to_deque(s);
	d.push_back(*max_element(d.begin(), d.end()));
	s = copy_deque_to_stack(d);
}

void remove_elem(St& s)
{
	Money value;
	cout << "Enter the value to remove : \n"; cin >> value;
	Deq d = copy_stack_to_deque(s);
	d.erase(remove(d.begin(), d.end(), value), d.end());
	s = copy_deque_to_stack(d);
}

void sort(St& s, string n = "")
{
	Deq d = copy_stack_to_deque(s);
	if (n == "less") sort(d.begin(), d.end(), Comp_less());
	else sort(d.begin(), d.end());
	s = copy_deque_to_stack(d);
}

void search(St& s, Money& m)
{
	Deq d = copy_stack_to_deque(s);
	auto i = find_if(d.begin(), d.end(), Equal_s());
	if (i != d.end())
		cout << "Found: " << *(i) << endl;
	else
		cout << "Not such element!" << endl;
}

void add_mean_all(St& s)
{
	Deq d = copy_stack_to_deque(s);
	Money sum;
	for (int i = 0; i < d.size(); i++)
	{
		sum = sum + d[i];
	}
	Money mean = sum / d.size();
	cout << "mean: " << mean << "\n";
	for_each(d.begin(), d.end(), [mean](Money& m)
		{
			m = m + mean;
		});
	s = copy_deque_to_stack(d);
}

int main()
{
	St s;
	int n;
	cout << "Enter deque size: "; cin >> n;
	s = make_stack(n);
	cout << "Stack: "; print_stack(s);
	push_max(s);
	cout << "push_max: "; print_stack(s);
	remove_elem(s);
	cout << "remove_elem: "; print_stack(s);
	sort(s);
	cout << "sort: "; print_stack(s);
	sort(s, "less");
	cout << "sort: "; print_stack(s);
	cout << "Enter value[find]: \n";
	cin >> s1;
	search(s, s1);
	add_mean_all(s);
	cout << "add_mean_all: "; print_stack(s);
}