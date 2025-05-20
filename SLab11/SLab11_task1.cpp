#include <iostream>
#include <deque>
using namespace std;

typedef deque<int>Deq;

Deq make_deque(int n)
{
	Deq d;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100 - 50;
		d.push_back(a);
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
	int max = NULL;
	for (int i = 0; i < d.size(); i++)
	{
		if (d[i] > max) max = d[i];
	}
	d.push_back(max);
	return d;
}

Deq remove_elem(Deq d, int value)
{
	for (deque<int>::iterator di = d.begin(); di != d.end();)
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
	double sum = NULL;
	for (int i = 0; i < d.size(); i++)
	{
		sum += d[i];
	}
	double mean = sum / d.size();
	cout << mean << "\n";
	for (int i = 0; i < d.size(); i++)
	{
		d[i] += (int)mean;
	}
	return d;
}

int main()
{

	try 
	{
		deque<int> d;
		int n;
		cout << "Enter n: "; cin >> n;
		d = make_deque(n);
		cout << "deque: "; print_deque(d);
		d = push_back_max(d);
		cout << "push_back_max: "; print_deque(d);
		int value;
		cout << "Enter the value to remove: "; cin >> value;
		d = remove_elem(d, value);
		cout << "remove_elem: "; print_deque(d);
		d = add_mean_all(d);
		cout << "add_mean_all: "; print_deque(d);
	}
	catch (int)
	{
		cout << "Error!";
	}
	return 0;
}