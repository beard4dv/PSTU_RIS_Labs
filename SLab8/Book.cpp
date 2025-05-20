#include "Book.h"

Book::Book(void):Print()
{
	pages = 0;
	pubHouse = "";
}

Book::Book(string N, string A, int P, string PH):Print(N,A)
{
	pages = P;
	pubHouse = PH;
}

Book::Book(const Book& b)
{
	name = b.name;
	author = b.author;
	pages = b.pages;
	pubHouse = b.pubHouse;
}

Book::~Book(void) {}

void Book::Show()
{
	cout << "\nBOOK";
	cout << "\nName: " << name;
	cout << "\nAuthor: " << author;
	cout << "\nPages: " << pages;
	cout << "\nPublishing house: " << pubHouse;
}

void Book::Input()
{
	cout << "\nEnter name: ";
	getline(cin, name);
	cout << "\nEnter author: ";
	getline(cin, author);
	cout << "\nPages: ";
	while (true)
	{
		cin >> pages;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			cout << "Input error. Please enter int number: ";
		}
		else break;
	}
	cin.ignore();
	cout << "\nPublishing house: ";
	getline(cin, pubHouse);
}

int Book::Get_pages()
{
	return pages;
}

string Book::Get_pubHouse() 
{
	return pubHouse;
}

void Book::Set_pages(int P) 
{
	pages = P;

}

void Book::Set_pubHouse(string PH) 
{
	pubHouse = PH;
}

Book& Book::operator=(const Book& b)
{
	if (&b == this)return *this;
	name = b.name;
	author = b.author;
	pages = b.pages;
	pubHouse = b.pubHouse;
	return *this;
}