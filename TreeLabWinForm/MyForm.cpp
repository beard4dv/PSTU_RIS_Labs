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
	Application::Run(gcnew TreeLabWinForm::MyForm());
}