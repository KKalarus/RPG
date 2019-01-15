#include "pch.h"
#include "Archer.h"


Archer::Archer(CLASS)
{
}

int Archer::atak()
{
	if (this->actualMana >= 80) {
		LIME; cout << "STRZELASZ P£ON¥C¥ STRZA£¥!";
		this->actualMana -= 80;
		return (dex + attackValueMax) * 3;
	}
	else {
		LIME; cout << "NIE POSIADASZ WYSTARCZAJ¥CEJ ILOŒCI ENERGII! (80)";
		return 0;
	}
}

void Archer::lvlup()
{
	this->lvl++;
	this->dex += 2;
	this->freeAbilityPoints += 2;
}


Archer::~Archer()
{
}
