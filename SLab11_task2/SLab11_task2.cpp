#include <iostream>
#include <deque>
#include "Money.h"
using namespace std;

typedef deque<Money>Deq;

Deq make_deque(int n)
{
	Deq d;
	for (int i = 0; i < n; i++)
	{
		long r = rand() % 1000;
		int k = rand() % 100;
		Money m(r, k);
		d.push_back(m);
	}
	return d;
}

void print_deque(Deq d)
{
	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << " ";
	}
	cout << endl;
}

Deq push_back_max(Deq d)
{
	Money max = d[0];
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i] > max) max = d[i];
	}
	d.push_back(max);
	return d;
}

Deq remove_elem(Deq d, Money value)
{
	for (deque<Money>::iterator di = d.begin(); di != d.end();)
	{
		if (*di == value)
			di = d.erase(di);
		else
			di++;
	}
	return(d);
}

Deq add_mean_all(Deq d)
{
	Money sum;
	for (int i = 0; i < d.size(); i++)
	{
		sum = sum + d[i];
	}
	cout << sum << "\n";
	Money mean = sum / d.size();
	cout << mean << "\n";
	for (int i = 0; i < d.size(); i++)
	{
		d[i] = d[i] + mean;
	}
	return d;
}

int main()
{
	try
	{
		deque<Money> d;
		int n;
		cout << "Enter n: "; cin >> n;
		d = make_deque(n);
		cout << "deque: "; print_deque(d);
		d = push_back_max(d);
		cout << "push_back_max: "; print_deque(d);
		Money value;
		cout << "Enter the value to remove: \n"; cin >> value;
		d = remove_elem(d, value);
		cout << "remove_elem: "; print_deque(d);
		d = add_mean_all(d);
		cout << "add_mean_all: "; print_deque(d);
	}
	catch (int)
	{
		cout << "Error!";
	}
}