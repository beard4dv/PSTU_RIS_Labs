#include "Book.h"
#include "List.h"
#include "Dialog.h"

int main()
{
	cout << "m(num) \t- Make group\n+ \t- Add\n- \t- Delete\ns \t- Show\nz(num) \t- Show name elem\nq \t- Quit\n";
	Dialog D;
	D.Execute();
}