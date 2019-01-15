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
void drawBuySellBox()
{
	//x-2-32
	//y-5-15
	for (int y = 4; y < 17; y++) {
		for (int x = 1; x < 34; x++) {
			if (y > 4 && y < 16) {
				if (x == 1 || x == 33) {
					gotoxy(x, y);
					GOLDBG; cout << " ";
				}
			}
			else {
				gotoxy(x, y);
				GOLDBG; cout << " ";
			}
		}
	}
	WHITE;
}
void clearBuySellBox() {
	for (int y = 5; y < 16; y++) {
		for (int x = 2; x < 33; x++) {
			gotoxy(x, y);
			BLACKBG; cout << " ";
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
void drawTopLeftBox() {
	for (int i = 1; i < 30; i++) {
		for (int j = 1; j < 43; j++) {
			gotoxy(j, i);
			GOLDBG; cout << " ";
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

bool menu() {
	char k;
	gotoxy(57, 17);
	YELLOW; cout << "WCISNIJ ENTER BY ZACZ¥Æ PRZYGODÊ";
	gotoxy(57, 18);
	YELLOW; cout << " WCISNIJ ESCAPE BY WYJŒÆ Z GRY";
	do {
		k=_getch();
		if (k == ENTER) return true;
		if (k == ESC) return false;
	} while (true);
}

void ShowConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}