#include "MyForm.h"
#define NOCRYPT
#define NOMINMAX
#define NOBITMAP
#define NOSERVICE
#define byte _byte 
#include <Windows.h>

using namespace System;
using namespace System::Windows::Forms;

[STAThreadAttribute]
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	//GraphLabWinForm::MyForm form;
	//Application::Run(% form);
	Application::Run(gcnew GraphLabWinForm::MyForm());
}