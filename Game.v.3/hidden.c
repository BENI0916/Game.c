#include <windows.h>

void hidden()
{
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;
	GetConsoleCursorInfo(hOut,&cci);
	cci.bVisible=0;
	SetConsoleCursorInfo(hOut,&cci);
}
