#include "pch.h"
#include "GUI.h"
#include <string>
#include "Dialogi.h"

GUI::GUI()
{
}


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
	character->moveStar();
	gotoxy(14, 30);
	BLUE; cout << "IMIE: "; WHITE;
	gotoxy(22, 30);
	cout << character->getName();
		gotoxy(35, 30);
		BLUE; cout << "SI£A: "; WHITE;
		gotoxy(50, 30);
		cout << character->getStr();
			gotoxy(63, 30);
			BLUE; cout << "Atak: "; WHITE;
			gotoxy(78, 30);
			cout << character->getMinAttack() << "-" << character->getMaxAttack();
				gotoxy(91, 30);
				BLUE; cout << "HP Potions: "; WHITE;
				gotoxy(106, 30);
				cout << character->getHPotions();
	gotoxy(14, 31);
	BLUE; cout << "KLASA: "; WHITE;
	gotoxy(22, 31);
	cout << character->getClass();
		gotoxy(35, 31);
		BLUE; cout << "ZWINNOŒÆ: "; WHITE;
		gotoxy(50, 31);
		cout << character->getDex();
			gotoxy(63, 31);
			BLUE; cout << "ARMOR: "; WHITE;
			gotoxy(78, 31);
			cout << character->getArmor();
				gotoxy(91, 31);
				BLUE; cout << "CEBULIONY: "; WHITE;
				gotoxy(106, 31);
				cout << character->getMoney();
	gotoxy(14, 32);
	BLUE; cout << "RASA: "; WHITE; 
	gotoxy(22, 32);
	cout << character->getRace();
		gotoxy(35, 32);
		BLUE; cout << "WYTRZYMA£OŒÆ: "; WHITE;
		gotoxy(50, 32);
		cout << character->getSt();
			gotoxy(63, 32);
			BLUE; cout << "HP: "; WHITE;
			gotoxy(78, 32);
			RED; cout << character->getActualHP(); WHITE; cout<< "/" << character->getHP();
				gotoxy(91, 32);
				BLUE; cout << "X COORD: "; WHITE;
				gotoxy(106, 32);
				cout << character->getPlayerX();
	gotoxy(14, 33);
	BLUE; cout << "LVL: "; WHITE; 
	gotoxy(22, 33);
	cout << character->getLvl();
		gotoxy(35, 33);
		BLUE; cout << "INTELIGENCJA: "; WHITE;
		gotoxy(50, 33);
		cout << character->getIn();
			gotoxy(63, 33);
			BLUE; cout << "MANA: "; WHITE;
			gotoxy(78, 33);
			cout << character->getActualMana() << "/" << character->getMana();
				gotoxy(91, 33);
				BLUE; cout << "Y COORD: "; WHITE;
				gotoxy(106, 33);
				cout << character->getPlayerY();
	gotoxy(14, 34);
	BLUE; cout << "XP: "; WHITE;
	gotoxy(22, 34);
	cout << character->getXp(); cout << "/" << character->getNextXp();
		gotoxy(35, 34);
		BLUE; cout << "SZCZÊŒCIE: "; WHITE;
		gotoxy(50, 34);
		cout << character->getLu();
			gotoxy(63, 34);
			BLUE; cout << "MANA Potions: "; WHITE;
			gotoxy(78, 34);
			cout << character->getMPotions();
				gotoxy(91, 34);
				BLUE; cout << "Miejsce: "; WHITE;
				gotoxy(106, 34);
				switch (character->getActualPlace()) {
				case MT_FOREST:
					cout << "LAS";
					break;
				case MT_MOUNTAINS:
					cout << "GÓRY";
					break;
				case MT_CAVE:
					cout << "JASKINIA";
					break;
				case MT_HOUSE:
					cout << "DOMEK";
					break;
				case MT_CITY:
					cout << "MIASTO";
					break;
				}
}
void GUI::CharOptions(Postac *character, Postac**pointer) {
	char k;
	do {
		k = _getch();
		switch (k) {
		case 'i':
			drawEQ(character);
			drawGUI(character);
			break;
		case 'b':
			drawStatMenu(pointer);
			drawGUI(character);
			break;
		case DIR_UP:
			if (character->moveUp()) {
				character->visit();
				drawGUI(character);
			}
			break;
		case DIR_DOWN:
			if(character->moveDown()){
				character->visit();
				drawGUI(character);
			}
			break;
		case DIR_LEFT:
			if(character->moveLeft()) {
				character->visit();
				drawGUI(character);
			}
			break;
		case DIR_RIGHT:
			if(character->moveRight()){
				character->visit();
				drawGUI(character);
			}
			break;
		case ENTER: //Odroczone odwiedzenie lokacji.
			character->visit();
			drawGUI(character);
		}
	} while (true);
}
void GUI::updateStats(Postac *character) {
	clearStatsBox();
gotoxy(14, 30);
	BLUE; cout << "IMIE: "; WHITE;
	gotoxy(22, 30);
	cout << character->getName();
		gotoxy(35, 30);
		BLUE; cout << "SI£A: "; WHITE;
		gotoxy(50, 30);
		cout << character->getStr();
			gotoxy(63, 30);
			BLUE; cout << "Atak: "; WHITE;
			gotoxy(78, 30);
			cout << character->getMinAttack() << "-" << character->getMaxAttack();
				gotoxy(91, 30);
				BLUE; cout << "HP Potions: "; WHITE;
				gotoxy(106, 30);
				cout << character->getHPotions();
	gotoxy(14, 31);
	BLUE; cout << "KLASA: "; WHITE;
	gotoxy(22, 31);
	cout << character->getClass();
		gotoxy(35, 31);
		BLUE; cout << "ZWINNOŒÆ: "; WHITE;
		gotoxy(50, 31);
		cout << character->getDex();
			gotoxy(63, 31);
			BLUE; cout << "ARMOR: "; WHITE;
			gotoxy(78, 31);
			cout << character->getArmor();
				gotoxy(91, 31);
				BLUE; cout << "CEBULIONY: "; WHITE;
				gotoxy(106, 31);
				cout << character->getMoney();
	gotoxy(14, 32);
	BLUE; cout << "RASA: "; WHITE; 
	gotoxy(22, 32);
	cout << character->getRace();
		gotoxy(35, 32);
		BLUE; cout << "WYTRZYMA£OŒÆ: "; WHITE;
		gotoxy(50, 32);
		cout << character->getSt();
			gotoxy(63, 32);
			BLUE; cout << "HP: "; WHITE;
			gotoxy(78, 32);
			RED; cout << character->getActualHP(); WHITE; cout<< "/" << character->getHP();
				gotoxy(91, 32);
				BLUE; cout << "X COORD: "; WHITE;
				gotoxy(106, 32);
				cout << character->getPlayerX();
	gotoxy(14, 33);
	BLUE; cout << "LVL: "; WHITE; 
	gotoxy(22, 33);
	cout << character->getLvl();
		gotoxy(35, 33);
		BLUE; cout << "INTELIGENCJA: "; WHITE;
		gotoxy(50, 33);
		cout << character->getIn();
			gotoxy(63, 33);
			BLUE; cout << "MANA: "; WHITE;
			gotoxy(78, 33);
			cout << character->getActualMana() << "/" << character->getMana();
				gotoxy(91, 33);
				BLUE; cout << "Y COORD: "; WHITE;
				gotoxy(106, 33);
				cout << character->getPlayerY();
	gotoxy(14, 34);
	BLUE; cout << "XP: "; WHITE;
	gotoxy(22, 34);
	cout << character->getXp(); cout << "/" << character->getNextXp();
		gotoxy(35, 34);
		BLUE; cout << "SZCZÊŒCIE: "; WHITE;
		gotoxy(50, 34);
		cout << character->getLu();
			gotoxy(63, 34);
			BLUE; cout << "MANA Potions: "; WHITE;
			gotoxy(78, 34);
			cout << character->getMPotions();
				gotoxy(91, 34);
				BLUE; cout << "Miejsce: "; WHITE;
				gotoxy(106, 34);
				switch (character->getActualPlace()) {
				case MT_FOREST:
					cout << "LAS";
					break;
				case MT_MOUNTAINS:
					cout << "GÓRY";
					break;
				case MT_CAVE:
					cout << "JASKINIA";
					break;
				case MT_HOUSE:
					cout << "DOMEK";
					break;
				case MT_CITY:
					cout << "MIASTO";
					break;
				}
}

void GUI::drawStatMenu(Postac **character) {
	char k;
	int wybor = 0;
	clearTopLeftBox();
	for (int i = 2; i < 42; i++) {
		gotoxy(i, 3);
		GOLDBG; cout << " "; BLACKBG;
	}
		gotoxy(17, 2);
		cout << "                    ";
		gotoxy(17, 2);
		BLUE; cout << "WOLNE PUNKTY: " << (*character)->getFreePoints(); WHITE;

		gotoxy(3, 5);
		cout << "SILA: "; YELLOW; cout <<  (*character)->getStr(); WHITE;
		gotoxy(3, 7);
		 cout << "ZRÊCZNOŒÆ: " << (*character)->getDex(); 
		gotoxy(3, 9);
		 cout << "INTELIGENCJA: " << (*character)->getIn(); 
		gotoxy(3, 11);
		 cout << "WYTRZYMA£OŒÆ: " << (*character)->getSt(); 
		gotoxy(3, 13);
		 cout << "SZCZÊŒCIE: " << (*character)->getLu(); 
	do {
		gotoxy(17, 2);
		cout << "                    ";
		gotoxy(17, 2);
		BLUE; cout << "WOLNE PUNKTY: " << (*character)->getFreePoints(); WHITE;
		k = _getch();
		if (wybor > 4) wybor = 4;
		else if (wybor < 0) wybor = 0;
		switch (k) {
		case DIR_DOWN:
			wybor++;
			break;
		case DIR_UP:
			wybor--;
			break;
		case DIR_RIGHT:
			if ((*character)->getFreePoints() > 0) {
				switch (wybor) {
				case 0:
					(*character)->modifyStr(1);
					(*character)->modifyFreePoints(-1);
					break;
				case 1:
					(*character)->modifyDex(1);
					(*character)->modifyFreePoints(-1);
					break;
				case 2:
					(*character)->modifyIn(1);
					(*character)->modifyFreePoints(-1);
					break;
				case 3:
					(*character)->modifySt(1);
					(*character)->modifyFreePoints(-1);
					break;
				case 4:
					(*character)->modifyLu(1);
					(*character)->modifyFreePoints(-1);
					break;
				}
			}
		}
		switch (wybor) {
		case 0:
			WHITE;
			gotoxy(3, 5);
			cout << "SILA: "; YELLOW; cout << (*character)->getStr(); WHITE;
			gotoxy(3, 7);
			cout << "ZRÊCZNOŒÆ: " << (*character)->getDex();
			gotoxy(3, 9);
			cout << "INTELIGENCJA: " << (*character)->getIn();
			gotoxy(3, 11);
			cout << "WYTRZYMA£OŒÆ: " << (*character)->getSt();
			gotoxy(3, 13);
			cout << "SZCZÊŒCIE: " << (*character)->getLu();
			break;
		case 1:
			WHITE;
			gotoxy(3, 5);
			cout << "SILA: "; cout << (*character)->getStr();
			gotoxy(3, 7);
			cout << "ZRÊCZNOŒÆ: "; YELLOW; cout << (*character)->getDex(); WHITE;
			gotoxy(3, 9);
			cout << "INTELIGENCJA: " << (*character)->getIn();
			gotoxy(3, 11);
			cout << "WYTRZYMA£OŒÆ: " << (*character)->getSt();
			gotoxy(3, 13);
			cout << "SZCZÊŒCIE: " << (*character)->getLu();
			break;
		case 2:
			WHITE;
			gotoxy(3, 5);
			cout << "SILA: ";  cout << (*character)->getStr();
			gotoxy(3, 7);
			cout << "ZRÊCZNOŒÆ: " << (*character)->getDex();
			gotoxy(3, 9);
			cout << "INTELIGENCJA: "; YELLOW; cout << (*character)->getIn(); WHITE;
			gotoxy(3, 11);
			cout << "WYTRZYMA£OŒÆ: " << (*character)->getSt();
			gotoxy(3, 13);
			cout << "SZCZÊŒCIE: " << (*character)->getLu();
			break;
		case 3:
			WHITE;
			gotoxy(3, 5);
			cout << "SILA: ";  cout << (*character)->getStr();
			gotoxy(3, 7);
			cout << "ZRÊCZNOŒÆ: " << (*character)->getDex();
			gotoxy(3, 9);
			cout << "INTELIGENCJA: " << (*character)->getIn();
			gotoxy(3, 11);
			cout << "WYTRZYMA£OŒÆ: "; YELLOW; cout << (*character)->getSt(); WHITE;
			gotoxy(3, 13);
			cout << "SZCZÊŒCIE: " << (*character)->getLu();
			break;
		case 4:
			WHITE;
			gotoxy(3, 5);
			cout << "SILA: "; (*character)->getStr();
			gotoxy(3, 7);
			cout << "ZRÊCZNOŒÆ: " << (*character)->getDex();
			gotoxy(3, 9);
			cout << "INTELIGENCJA: " << (*character)->getIn();
			gotoxy(3, 11);
			cout << "WYTRZYMA£OŒÆ: " << (*character)->getSt();
			gotoxy(3, 13);
			cout << "SZCZÊŒCIE: "; YELLOW; cout << (*character)->getLu(); WHITE;
			break;
		}
	} while (k != ENTER && k!=ESC);
}

void GUI::drawEQ(Postac *character) {
	int i = 0;
	char k;
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
		if (k == ENTER) {
			character->equipItem(i);
			updateStats(character);
		}
		if (k == 'x') {
			character->dropItem(i);
		}
	} while (k != ESC);
}

GUI::~GUI()
{
}
