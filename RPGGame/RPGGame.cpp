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
	game.drawGUI(postac);
	game.drawEQ(postac);
}
int main()
{
	setlocale(LC_CTYPE, "Polish");
	setwindowsize(148, 35);
	test();
	_getch();
}
