#include "Money.h"

int make_file(const char* f_name)
{
	fstream stream(f_name, ios::out | ios::trunc);
	if (!stream)return -1;
	int n;
	Money m;
	cout << "N: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "#" << i+1 << "\n";
		cin >> m;
		stream << m << "\n";
	}
	stream.close();
	return n;
}

int print_file(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Money m; int i = 0;
	while (stream >> m)
	{
		cout << "#" << i+1 << "\n";
		cout << m << "\n";
		i++;
	}
	stream.close();
	return i;
}

int del_file(const char* f_name, long rub, int kop)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	int i = 0; Money m;
	while (stream >> m)
	{
		if (stream.eof())break;
		i++;
		if (m.get_rub() != rub || m.get_kop() != kop) temp << m;

	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int add_file(const char* f_name, long rub, int kop)

{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Money m; int n, l = 0;
	while (stream >> m)
	{
		if (stream.eof())break;
		if (m.get_rub() == rub && m.get_kop() == kop)
		{
			temp << m;
			cout << "N: "; cin >> n;
			for (int i = 0; i < n; i++)
			{
				cout << "#" << i + 1 << "\n";
				cin >> m;
				temp << m << "\n";
			}
			l++;
		}
		else temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}

int add_end(const char* f_name)
{
	fstream stream(f_name, ios::app);
	if (!stream)return -1;
	int n;
	Money m;
	cout << "N: "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "#" << i + 1 << "\n";
		cin >> m;
		stream << m << "\n";
	}
	stream.close();
	return 1;
}

int change_file(const char* f_name, long rub, int kop)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream)return -1;
	Money m; int i = 0, l = 0;
	char x;
	while (stream >> m)
	{
		if (stream.eof())break;
		i++;
		if (m.get_rub() == rub && m.get_kop() == kop)
		{
			cout << "#" << i << ": " << m << " - is changing(" << m << "-1,50)... Continue[y/n]?\n";
			cin >> x;
			if (x == 'n' || x == 'N')break;
			if (m.get_rub() < 2 && m.get_kop() < 50)
			{
				cout << "Error. Out of range!";
				temp << m;
			}
			else
			{
				m = m - 1.50;
				temp << m;
			}
			l++;
		}
		else temp << m;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return l;
}