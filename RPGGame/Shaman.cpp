#include "pch.h"
#include "Shaman.h"


Shaman::Shaman(CLASS)
{
}


int Shaman::atak()
{
	if (this->actualMana >= 50) {
		LIME; cout << "LECZYSZ SI� KOSZTEM MA�EJ ILO�CI MANY!";
		this->actualMana -= 50;
		return lu * 5 + in*2;
	}
	else {
		LIME; cout << "NIE POSIADASZ WYSTARCZAJ�CEJ ILO�CI ENERGII! (90)";
		return 0;
	}
}

void Shaman::lvlup()
{
	this->lvl++;
	this->lu += 2;
	this->freeAbilityPoints += 2;
}

Shaman::~Shaman()
{
}
