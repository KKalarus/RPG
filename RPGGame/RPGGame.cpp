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

void game() {
	CLS;
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
	ShowConsoleCursor(false);
	if (menu()) game();
	else return 0;
}
