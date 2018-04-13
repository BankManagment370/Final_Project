#include <Alt.h>  
COORD coord = { 0,0 };

void gotoxy(int x, int y)         //For Setting the position of Cursor
{

	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
