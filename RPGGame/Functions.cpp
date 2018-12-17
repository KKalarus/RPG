#include "pch.h"
#include "Functions.h"

void gotoxy(int x, int y)
{

	COORD c;

	c.X = x - 1;

	c.Y = y - 1;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);

}

void color(int textColor, int bgColor)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16)));
}

void setwindowsize(int x, int y)
{
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r);
	MoveWindow(console, r.left, r.top, 1220, 600, TRUE);
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
	//ShowScrollBar(GetConsoleWindow(), SB_BOTH, false);
}

