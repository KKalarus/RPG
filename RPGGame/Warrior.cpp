#include "pch.h"
#include "Warrior.h"

Warrior::Warrior(CLASS)
{
}

int Warrior::atak()
{
	if (this->actualMana >= 75) {
		LIME; cout << "WYKORZYSTUJESZ S£ABY PUNKT PRZECIWNIKA!";
		this->actualMana -= 75;
		return this->attackValueMax * 2;
	}
	else {
		LIME; cout << "NIE POSIADASZ WYSTARCZAJ¥CEJ ILOŒCI ENERGII! (75)";
		return 0;
	}
}

void Warrior::lvlup()
{
	this->lvl++;
	this->modifyStr(2);
	this->freeAbilityPoints += 2;
}


Warrior::~Warrior()
{
}
