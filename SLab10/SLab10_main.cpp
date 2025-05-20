#include "file_work.h"

int main()
{
	int k, c;
	char file_name[30] = "";
	do
	{
		cout << "\nFile [" << file_name << "]";
		cout << "\n1. Select file name";
		cout << "\n2. Make file";
		cout << "\n3. Print file";
		cout << "\n4. Delete record from file";
		cout << "\n5. Add record to file";
		cout << "\n6. Change record in file";
		cout << "\n0. Exit\n";
		cout << ">>"; cin >> c;
		switch (c)
		{
		case 1: 
			cout << "Enter file name: "; cin >> file_name;
			break;
		case 2:
			k = make_file(file_name);
			if (k < 0)cout << "Can't make file";
			break;
		case 3:
			k = print_file(file_name);
			if (k == 0)cout << "Empty file\n";
			if (k < 0)cout << "Can't read file\n";
			break;
		case 4:
			long rub; cout << "rub: "; cin >> rub;
			int kop; cout << "kop: "; cin >> kop;
			k = del_file(file_name, rub, kop);
			if (k < 0)cout << "Can't read file";
			break;
		case 5:
			cout << "rub: "; cin >> rub;
			cout << "kop: "; cin >> kop;
			k = add_file(file_name, rub, kop);
			if (k < 0) cout << "Can't read file";
			if (k == 0) k = add_end(file_name);
			break;
		case 6:
			cout << "rub: "; cin >> rub;
			cout << "kop: "; cin >> kop;
			k = change_file(file_name, rub, kop);
			if (k < 0) cout << "\nCan't read file";
			if (k == 0) cout << "\nNot such record";
			break;
		}
	} 
	while (c != 0);
}