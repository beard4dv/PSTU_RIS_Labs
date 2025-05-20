#include "F:\Labs C++\SLab11_task2\money.h"
#include <deque>
#include <iostream>
#include <algorithm>

using namespace std;

typedef deque<Money> Deq;
Money s;

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
		return m == s;
	}
};

Deq make_deque(int n)
{
	Money m;
	Deq d;
	for (int i = 0; i < n; i++)
	{
		cout << "Enter m[" << i << "]: \n";
		cin >> m;
		d.push_back(m);
	}
	return d;
}

void print_deque(Deq d)
{
	for (int i = 0; i < d.size(); i++) cout << d[i] << " ";
	cout << "\n";
}

void search(Deq& d, Money& m)
{
	auto i = find_if(d.begin(), d.end(), Equal_s());
	if (i != d.end())
		cout << "Found: " << * (i) << endl;
	else
		cout << "Not such element!" << endl;
}

void add_mean_all(Deq& d)
{
	Money sum;
	for (int i = 0; i < d.size(); i++)
	{
		sum = sum + d[i];
	}
	Money mean = sum / d.size();
	cout << "mean: " << mean << "\n";;
	for_each(d.begin(), d.end(), [mean](Money& m)
		{
			m = m + mean;
		});
}

int main()
{
	int n;
	cout << "Enter deque size: "; cin >> n;
	Deq d; d = make_deque(n);
	cout << "Deque: "; print_deque(d);
	d.push_back(*max_element(d.begin(), d.end()));
	cout << "push_back_max: "; print_deque(d);
	Money value;
	cout << "Enter the value to remove: \n"; cin >> value;
	d.erase(remove(d.begin(), d.end(), value), d.end());
	cout << "remove: "; print_deque(d);
	sort(d.begin(), d.end());
	cout << "sort: "; print_deque(d);
	sort(d.begin(), d.end(), Comp_less());
	cout << "sort: "; print_deque(d);
	cout << "Enter value[find]: \n";
	cin >> s;
	search(d, s);
	add_mean_all(d);
	cout << "add_mean_all: "; print_deque(d);
}