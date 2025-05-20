#include <set>
#include <iostream>
#include "F:\Labs C++\SLab11_task2\money.h"

using namespace std;

typedef set<Money, less<Money>> TSet;
TSet::iterator it;

TSet make_set(int n)
{
	TSet s;
	Money a;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter a[" << i << "]: \n";
		cin >> a;
		s.insert(a);
	}
	return s;
}

void print_set(TSet s)
{
	for (it = s.begin(); it != s.end(); it++)
	{
		cout << *it << " ";
	}
	cout << "\n";
}

void add_mean_all(TSet& s)
{
	Money sum;
	for (it = s.begin(); it != s.end(); it++)
	{
		sum = sum + *it;
	}
	Money mean = sum / s.size();
	cout << "mean: " << mean << "\n";
	TSet tempSet;
	for (it = s.begin(); it != s.end(); it++)
	{
		tempSet.insert(*it + mean);
	}
	s = tempSet;
}

int main()
{
	int n;
	cout << "Enter set size: "; cin >> n;
	TSet set = make_set(n);
	cout << "Set: "; print_set(set);
	Money value; cout << "Enter the value to remove: \n"; cin >> value;
	set.erase(value);
	cout << "remove_elem: "; print_set(set);
	add_mean_all(set);
	cout << "add_mean_all: "; print_set(set);
}