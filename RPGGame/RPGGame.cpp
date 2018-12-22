#pragma once
#include "pch.h"
#include "RPGGame.h"
#include "GUI.h"
/*		#######################
		##TYTU£ DO WYMYŒLENIA##
		##BUILD-NoOneCaresTBH##
		##KRZYSZTOF   KALARUS##
		#######################		*/

using namespace std; 

void test() {
	GUI game;
	game.intro(pointer, warrior, archer, mage, thief, shaman);
	do {
		game.drawGUI(postac);
		game.drawEQ(postac);
	} while (true);
}
int main()
{
	system("MODE CON: COLS=150 LINES=35");
	setlocale(LC_CTYPE, "Polish");
	//setwindowsize(150, 35);
	//HWND console = GetConsoleWindow();
	//console.WindowWidth = console.LargestWindowWidth();
	test();
	_getch();
}
