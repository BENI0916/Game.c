#include <conio.h>

int getch_noblock()
{
	if(_kbhit())
		return _getch();
	else
		return -1;
}
