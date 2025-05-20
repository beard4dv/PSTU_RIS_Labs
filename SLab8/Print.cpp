#include "Print.h"

Print::Print(void)
{
	name = "";
	author = "";
}

Print::Print(string N, string A)
{
	name = N;
	author = A;
}

Print::Print(const Print& p)
{
	name = p.name;
	author = p.author;
}

Print::~Print(void) {}

void Print::Show()
{
	cout << "\nPAGES";
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
}

void Print::Input()
{
	cout << "\nEnter name: ";
	getline(cin, name);
	cout << "\nEnter author: ";
	getline(cin, author);
}

//string Print::Get_name() 
//{
//	return name;
//}

string Print::Get_author() 
{
	return author;
}

void Print::Set_name(string N)
{
	name = N;
}

void Print::Set_author(string A)
{
	author = A;
}

Print& Print::operator=(const Print& p)
{
	if (&p == this)return *this;
	name = p.name;
	author = p.author;
	return *this;
}