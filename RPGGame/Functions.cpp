#include "pch.h"
#include "Functions.h"
#include <random>
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
	MoveWindow(console, r.left, r.top, 1233, 599, TRUE);
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), c);
	//ShowScrollBar(GetConsoleWindow(), SB_BOTH, false);
}

void outline() {
	for (int i = 1; i <= 35; i++) { //This loop generates basic outline of GUI in golden color.
		for (int j = 1; j <= 150; j++) {
			if (i == 1 || i == 29 || i == 35) {
				GOLDBG;
				cout << " ";
				BLACKBG;
			}
			else if ((i > 1 && i < 35) && (j == 1 || j == 150) || (i > 29 && i < 35) && (j == 150 || j == 12) || ((i > 1 && i < 29) && (j == 42))) {
				gotoxy(j, i);
				GOLDBG;
				cout << " ";
				BLACKBG;
			}
		}
	}
}
void clearTopLeftBox() {
	for (int i = 2; i < 29; i++) {
		for (int j = 2; j < 42; j++) {
			gotoxy(j, i);
			BLACKBG; cout << " ";
		}
	}
}
void clearStatsBox() {
	for (int i = 30; i < 35; i++) {
		for (int j = 13; j < 150; j++) {
			gotoxy(j, i);
			BLACKBG; cout << " ";
		}
	}
}
void clearFightBox() {
	for (int i = 2; i < 27; i++) {
		for (int j = 43; j < 150; j++) {
			gotoxy(j, i);
			BLACKBG; cout << " ";
		}
	}
}

int chanceR() {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> chanceR(1, 100);
	return chanceR(rng);
}
