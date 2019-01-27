#include "pch.h"
#include "Item.h"
#include <random>
#include <fstream>
#include <vector>

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

Item::Item(TYPE typ, int forWho, string name, int needStr, int needDex, int needIn, int needSt, int needLu, int giveStr, int giveDex, int giveIn, int giveSt, int giveLu, int attStr, int armor, QUALITY quality,int price)
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

	this->price = price;

}

TYPE Item::getType()
{
	return this->typ;
}
void Item::drop() 
{
	this->typ = T_FREESPACE;
}
string nameOfItem(int id) {
	std::mt19937 rng;
	rng.seed(std::random_device()());

	fstream plik;
	vector <string> itemNames;

	if(id==0) plik.open("Swords.txt");
	else if (id == 1) plik.open("Bows.txt");
	else if (id == 2) plik.open("Wands.txt");
	else if (id == 3) plik.open("Daggers.txt");
	else if (id == 4) plik.open("OrcStuff.txt");
	else if (id == 5) plik.open("Armors.txt");
	else if (id == 6) plik.open("Necklaces.txt");
	else if (id == 7) plik.open("Rings.txt");

	do {
		string temp;
		getline(plik, temp);
		itemNames.push_back(temp);
	} while (!plik.eof());

	std::uniform_int_distribution<std::mt19937::result_type> nameRand(0, itemNames.size()-1);
	int x = nameRand(rng);
	return itemNames[x];
}
Item Item::generateRandomItem(int playerLevel) {


	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> levelRand(playerLevel,playerLevel+4);
	std::uniform_int_distribution<std::mt19937::result_type> typeRand(0,3);
	std::uniform_int_distribution<std::mt19937::result_type> qualityRand(1,20);
	std::uniform_int_distribution<std::mt19937::result_type> classRand(0,4);

	int level = levelRand(rng) - 2; //Random item level (playerlvl+-2)
	if (level < 1) {
		level = 1;
	} 



	int x = 1 + level * 4 / static_cast<int>(quality + 1) / 3;
	if (x < level) x = level;

	TYPE type = static_cast<TYPE>(typeRand(rng)); // Random type of item
	QUALITY quality;
	int qualityTemp = qualityRand(rng); //Random quality - trash 20%, common 65%, rare 10%, legendary 5%!
	if (qualityTemp > 4) {
		if (qualityTemp >= 18) {
			if (qualityTemp == 20) quality = Q_LEGENDARY;
			else quality = Q_RARE;
		}
		else quality = Q_COMMON;
	}
	else quality = Q_TRASH;

	int q; //modifier for jevelery
	if (quality == Q_LEGENDARY) q = 3;
	if (quality == Q_RARE) q = 2;
	if (quality == Q_COMMON) q = 1;
	if (quality == Q_TRASH) q = 0;

	int forWho = classRand(rng);

	std::uniform_int_distribution<std::mt19937::result_type> randPerkq(1, level + q*level/static_cast<int>(quality+1));
	std::uniform_int_distribution<std::mt19937::result_type> randPerk(1, level + quality);
	std::uniform_int_distribution<std::mt19937::result_type> armorRand(level, level + level * 4);
	std::uniform_int_distribution<std::mt19937::result_type> attackRand(level, level + level * 4);
	std::uniform_int_distribution<std::mt19937::result_type> baseNeedRand(level, 1 + level * 4 / static_cast<int>(quality + 1)); //Main needed perk for class - [level of Item ;level of Item *4/quality]
	std::uniform_int_distribution<std::mt19937::result_type> secondaryNeedRand(level, x); //Second needed perk



	int attStr = 0;
	int armor = 0;

	int needStr = 0;
	int needDex = 0;
	int needIn = 0;
	int needSt = 0;
	int needLu = 0;

	int givesStr = 0;
	int givesDex = 0;
	int givesIn = 0;
	int givesSt = 0;
	int givesLu = 0;

	string name = "DEFAULT NAME";

	switch (static_cast<int>(type)) {
	case 0: //Generates weapon
		attStr = attackRand(rng) / static_cast<int>(quality + 1); //Attack strength is randomised attack divided by quality + 1
		switch (forWho) {
		case 0:
		{
			name = nameOfItem(forWho);
			needStr = baseNeedRand(rng);
			needSt = secondaryNeedRand(rng);
			needIn = randPerk(rng);
			needDex = randPerk(rng);
			needLu = randPerk(rng);
			break;
		}
		case 1:
			name = nameOfItem(forWho);
			needDex = baseNeedRand(rng);
			needLu = secondaryNeedRand(rng);
			needIn = randPerk(rng);
			needStr = randPerk(rng);
			needLu = randPerk(rng);
			break;
		case 2:
			name = nameOfItem(forWho);
			needIn = baseNeedRand(rng);
			needLu = secondaryNeedRand(rng);
			needSt = randPerk(rng);
			needStr = randPerk(rng);
			needDex = randPerk(rng);
			break;
		case 3:
			name = nameOfItem(forWho);
			needSt = baseNeedRand(rng);
			needDex = secondaryNeedRand(rng);
			needIn = randPerk(rng);
			needStr = randPerk(rng);
			needLu = randPerk(rng);
			break;
		case 4:
			name = nameOfItem(forWho);
			needLu = baseNeedRand(rng);
			needStr = secondaryNeedRand(rng);
			needIn = randPerk(rng);
			needDex = randPerk(rng);
			needLu = randPerk(rng);
			break;
		}
		break;
	case 1: //Random armor
		forWho = 5;
		name = nameOfItem(forWho);
		armor = armorRand(rng) / static_cast<int>(quality+1);
		needIn = randPerk(rng) / static_cast<int>(quality + 1);
		needDex = randPerk(rng) / static_cast<int>(quality + 1);
		needLu = randPerk(rng) / static_cast<int>(quality + 1);
		needSt = randPerk(rng) / static_cast<int>(quality + 1);
		needStr = randPerk(rng) / static_cast<int>(quality + 1);
		break;
	case 2: //random Necklace
		forWho = 5;
		name = nameOfItem(6);
		givesIn = randPerkq(rng) / static_cast<int>(quality + 1)+level/5;
		givesDex = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		givesLu = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		givesSt = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		givesStr = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		break;
	case 3: //random Ring
		forWho = 5;
		name = nameOfItem(7);
		givesIn = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		givesDex = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		givesLu = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		givesSt = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		givesStr = randPerkq(rng) / static_cast<int>(quality + 1) + level / 5;
		break;
	}
	if (needStr > 100) needStr = 100;
	if (needDex > 100) needDex = 100;
	if (needSt > 100) needSt = 100;
	if (needIn > 100) needIn = 100;
	if (needLu > 100) needLu = 100;

	if (givesStr > 25) givesStr = 25;
	if (givesDex > 25) givesDex = 25;
	if (givesSt > 25) givesSt = 25;
	if (givesIn > 25) givesIn = 25;
	if (givesLu > 25) givesLu = 25;

	int price = ((givesStr + givesDex + givesIn + givesLu + givesSt + attStr + armor) * 10)*(q + 1);
	return Item(type, forWho, name, needStr, needDex, needIn, needSt, needLu, givesStr, givesDex, givesIn, givesSt, givesLu, attStr, armor, quality, price);
}

void Item::showItem(int playerClass){
	gotoxy(2, 5);
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
		if (typ == 0 || typ == 1) {
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
			if (typ == 0) {
				gotoxy(2, 12);
				BLUE; cout << "Wartoœæ ataku: "; WHITE; cout << this->attStr << endl;
			}
			else {
				gotoxy(2, 12);
				BLUE; cout << "Wartoœæ obrony: "; WHITE; cout << this->armor << endl;
			}
		}
		else {
			gotoxy(2, 7);
			BLUE; cout << "Daje sily : "; WHITE; cout << this->giveStr << endl;
			gotoxy(2, 8);
			BLUE; cout << "Daje zwinnoœci : "; WHITE; cout << this->giveDex << endl;
			gotoxy(2, 9);
			BLUE; cout << "Daje inteligencji: "; WHITE; cout << this->giveIn << endl;
			gotoxy(2, 10);
			BLUE; cout << "Daje wytrzyma³oœci: "; WHITE; cout << this->giveSt << endl;
			gotoxy(2, 11);
			BLUE; cout << "Daje szczêœcia: "; WHITE; cout << this->giveLu << endl;
		}
		gotoxy(2, 13);
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
		gotoxy(2, 14);
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
		case 5:
			WHITE; cout << "KA¯DY";
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

int Item::getPrice() 
{
	return this->price;
}

Item::~Item()
{
}
