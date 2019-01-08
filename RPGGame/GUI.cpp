#include "pch.h"
#include "GUI.h"
#include <string>
#include "Dialogi.h"

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
			cout << character->getHPotions();
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
void GUI::CharOptions(Postac *character) {
	char k;
	do {
		k = _getch();
		switch (k) {
		case 'i':
			drawEQ(character);
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
			cout << character->getHPotions();
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
void GUI::drawEQ(Postac *character) {
	int i = 0;
	char k;
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
		if (k == ENTER) {
			character->equipItem(i);
			updateStats(character);
		}
	} while (k != ESC);
}

GUI::~GUI()
{
}
