#pragma once
#include "pch.h"
#include "RPGGame.h"
#include "GUI.h"
#include <random>

/*		#######################
		##TYTU£ DO WYMYŒLENIA##
		##BUILD-NoOneCaresTBH##
		##KRZYSZTOF   KALARUS##
		#######################		*/

using namespace std; 

void test() {
	GUI game;
	game.intro(pointer, warrior, archer, mage, thief, shaman);
	game.drawGUI(postac);
	do {
		game.CharOptions(postac, pointer);
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
	//postac->showmap(postac->mapPointer);
	_getch();
}
