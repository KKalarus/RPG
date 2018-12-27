#include "pch.h"
#include "Item.h"
#include <random>

Item::Item()
{
}

Item::Item(TYPE typ) {
	if (typ == T_FREESPACE) {
		this->typ = typ;
		this->needStr = 0;
		this->needDex = 0;
		this->needIn = 0;
		this->needSt = 0;
		this->needLu = 0;

		this->giveStr = 0;
		this->giveDex = 0;
		this->giveIn = 0;
		this->giveSt = 0;
		this->giveLu = 0;
	}
	else {
		Item(T_FREESPACE);
	}
}
Item::Item(TYPE typ, int forWho, string name, int needStr, int needDex, int needIn, int needSt, int needLu, int giveStr, int giveDex, int giveIn, int giveSt, int giveLu, int attStr, int armor, QUALITY quality)
{
	this->typ = typ;
	this->quality = quality;
	this->forWho = forWho;
	this->attStr = attStr;
	this->armor = armor;

	this->itemName = name;
	this->needStr = needStr;
	this->needDex = needDex;
	this->needIn = needIn;
	this->needSt = needSt;
	this->needLu = needLu;

	this->giveStr = giveStr;
	this->giveDex = giveDex;
	this->giveIn = giveIn;
	this->giveSt = giveSt;
	this->giveLu = giveLu;

}

TYPE Item::getType()
{
	return this->typ;
}

void Item::showItem(int playerClass){
	BLUE; cout << "Typ przedmiotu : "; WHITE;
	switch (static_cast<int>(this->typ)) {
	case 0:
		cout << "BROÑ";
		break;
	case 1:
		cout << "PANCERZ";
		break;
	case 2:
		cout << "NASZYJNIK";
		break;
	case 3:
		cout << "PIERŒCIEÑ";
		break;
	case 4:
		cout << "WOLNE MIEJSCE";
		break;
	}
	cout << endl;
	if ((static_cast<int>(this->typ)) != 4) {
		gotoxy(2, 6);
		BLUE; cout << "Nazwa: "; WHITE; cout << this->itemName << endl;
		gotoxy(2, 7);
		BLUE; cout << "Potrzebna sila : "; WHITE; cout << this->needStr << endl;
		gotoxy(2, 8);
		BLUE; cout << "Potrzebna zwinnosc : "; WHITE; cout << this->needDex << endl;
		gotoxy(2, 9);
		BLUE; cout << "Potrzebna inteligencja: "; WHITE; cout << this->needIn << endl;
		gotoxy(2, 10);
		BLUE; cout << "Potrzebna wytrzyma³oœæ: "; WHITE; cout << this->needSt << endl;
		gotoxy(2, 11);
		BLUE; cout << "Potrzebne szczêœcie: "; WHITE; cout << this->needLu << endl;
		gotoxy(2, 12);
		BLUE; cout << "Jakoœæ przedmiotu: ";
		switch (this->quality) {
		case 0:
			PINK; cout << "LEGENDARNY" << endl;
			break;
		case 1:
			LIME; cout << "RZADKI" << endl;
			break;
		case 2:
			WHITE; cout << "PRZECIÊTNY" << endl;
			break;
		case 3:
			GREY; cout << "ŒMIEÆ" << endl;
			break;
		}
		gotoxy(2, 13);
		BLUE; cout << "Wymagana klasa: "; WHITE;
		switch (this->forWho) {
		case 0:
			if (playerClass == forWho) {
				WHITE; cout << "WOJOWNIK";
			}
			else {
				RED; cout << "WOJOWNIK"; WHITE;
			}
			break;
		case 1:
			if (playerClass == forWho) {
				WHITE; cout << "£UCZNIK";
			}
			else {
				RED; cout << "£UCZNIK"; WHITE;
			}
			break;
		case 2:
			if (playerClass == forWho) {
				WHITE; cout << "MAG";
			}
			else {
				RED; cout << "MAG"; WHITE;
			}
			break;
		case 3:
			if (playerClass == forWho) {
				WHITE; cout << "Z£ODZIEJ";
			}
			else {
				RED; cout << "Z£ODZIEJ"; WHITE;
			}
			break;
		case 4:
			if (playerClass == forWho) {
				WHITE; cout << "SZAMAN";
			}
			else {
				RED; cout << "SZAMAN"; WHITE;
			}
			break;
		}
		gotoxy(2, 15);
		BLUE; cout << "ZA£O¯ONY: "; WHITE;
		switch (isItemEquiped()) {
			case true:
				GREEN; cout << "TAK"; WHITE;
				break;
			case false:
				cout << "NIE";
				break;
		}
	}
}

int Item::getGStr()
{
	return this->giveStr;
}

int Item::getNStr()
{
	return this->needStr;
}

int Item::getGDex()
{
	return this->giveDex;
}

int Item::getNDex()
{
	return this->needDex;
}

int Item::getGIn()
{
	return this->giveIn;
}

int Item::getNIn()
{
	return this->needIn;
}

int Item::getGSt()
{
	return this->giveSt;
}

int Item::getNSt()
{
	return this->needSt;
}

int Item::getGLu()
{
	return this->giveLu;
}

int Item::getNLu()
{
	return this->needLu;
}

int Item::getClass()
{
	return this->forWho;
}

int Item::getAttStr()
{
	return this->attStr;
}

int Item::getArmor()
{
	return this->armor;
}
void Item::equip() {
	this->isEquiped = true;
}
void Item::takeOff()
{
	this->isEquiped = false;
}
bool Item::isItemEquiped()
{
	return this->isEquiped;
}


Item::~Item()
{
}
