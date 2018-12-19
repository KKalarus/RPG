#include "pch.h"
#include "GUI.h"
#include <string>
#include "Dialogi.h"

void outline() {
	for (int i = 1; i <= 35; i++) { //This loop generates basic outline of GUI in golden color.
		for (int j = 1; j <= 150; j++) {
			if (i == 1 || i==29 || i == 35) {
				GOLDBG;
				cout << " ";
				BLACKBG;
			}
			else if ((i > 1 && i < 35) && (j == 1 || j == 150) || (i > 29 && i < 35) && (j == 150 || j == 12) || ((i > 1 && i < 29) && (j == 42))){
				gotoxy(j, i);
				GOLDBG;
				cout << " ";
				BLACKBG;
			}
		}
	}
}
void clearTopLeftBox() {
	{
		for (int i = 2; i < 29; i++) {
			for (int j = 2; j < 42; j++) {
				gotoxy(j, i);
				BLACKBG; cout << " ";
			}
		}
	}
}

GUI::GUI()
{
}
//To sie gdzieœ jebie
//O ju¿ naprawilem XD
void GUI::intro(Postac **postac, Warrior &warrior, Archer &archer, Mage &mage, Thief &thief, Shaman &shaman){
	CLASS klasa;
	Dialog1();
	klasa = (*postac)->chooseClass();
	switch (klasa) {
	case 0:
		*postac = &warrior;
		(*postac)->setClass(C_WARRIOR);
		break;
	case 1:
		*postac = &archer;
		(*postac)->setClass(C_ARCHER);
		break;
	case 2:
		*postac = &mage;
		(*postac)->setClass(C_MAGE);
		break;
	case 3:
		*postac = &thief;
		(*postac)->setClass(C_THIEF);
		break;
	case 4:
		*postac = &shaman;
		(*postac)->setClass(C_SHAMAN);
		break;
	}
	switch (klasa) {
	case 0:
		introWoj();
		break;
	case 1:
		introArch();
		break;
	case 2:
		introMage();
		break;
	case 3:
		introThief();
		break;
	case 4:
		introShaman();
		break;
	}

	Sleep(1000); cout << endl << " Wracaj¹c do rzeczy."; Sleep(900); cout << " Kim w ogóle jesteœ?"; Sleep(900); " G³uchy jesteœ czy co?!"; Sleep(1000);
	(*postac)->chooseRace();
	Dialog2();
	(*postac)->chooseName();
	CLS;
	WHITE;
	cout << "-Witaj, " << (*postac)->getName() << "."; Sleep(900);
	Dialog3();
	WHITE;
	(*postac)->buildCharacter();
	(*postac)->initializeEq();
}
void GUI::drawGUI(Postac *character)
{
	CLS;
	outline();
	gotoxy(14, 30);
	BLUE; cout << "IMIE: "; WHITE;
	gotoxy(22, 30);
	cout << character->getName();
	gotoxy(14, 31);
	BLUE; cout << "KLASA: "; WHITE;
	gotoxy(22, 31);
	cout << character->getClass();
	gotoxy(14, 32);
	BLUE; cout << "RASA: "; WHITE; 
	gotoxy(22, 32);
	cout << character->getRace();
	gotoxy(14, 33);
	BLUE; cout << "LVL: "; WHITE; 
	gotoxy(22, 33);
	cout << character->getLvl();
	gotoxy(14, 34);
	BLUE; cout << "XP: "; WHITE; 
	gotoxy(22, 34);
	cout << character->getXp();
}
void GUI::drawEQ(Postac *character) {
	int i = 2;
	char k;
	character->addItem();
	gotoxy(2, 5);
	character->showEq(i);
	do {
		clearTopLeftBox();
		for (int i = 2; i < 42; i++) {
			gotoxy(i, 4);
			GOLDBG; cout << " "; BLACKBG;
		}
		gotoxy(17, 2);
		BLUE; cout << "EKWIPUNEK"; WHITE;
		gotoxy(19, 3);
		if (i + 1 < 10) {
			YELLOW; cout << "0" << i + 1; WHITE;
		}
		else {
			YELLOW; cout << i + 1; WHITE;
		}
		cout << "/" << 15;
		gotoxy(2, 5);
		character->showEq(i);
		k = _getch();
		if (k == DIR_RIGHT) i++;
		else if (k == DIR_LEFT) i--;
		if (i < 0) i = 0;
		else if (i > 14) i = 14;
	} while (k != ESC);
}

GUI::~GUI()
{
}
