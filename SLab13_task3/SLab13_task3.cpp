#include "F:\Labs C++\SLab11_task2\money.h"
#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

typedef set<Money, less<Money>> TSet;
TSet::iterator it;
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

void search(TSet& s, Money& m)
{
	auto i = find_if(s.begin(), s.end(), Equal_s());
	if (i != s.end())
		cout << "Found: " << *(i) << endl;
	else
		cout << "Not such element!" << endl;
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
	for_each(s.begin(), s.end(), [&tempSet, mean](const Money& m)
		{
			tempSet.insert(m + mean);
		});
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
	cout << "Enter value[find]: \n";
	cin >> s1;
	search(set, s1);
	add_mean_all(set);
	cout << "add_mean_all: "; print_set(set);
}