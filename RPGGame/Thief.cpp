#include "pch.h"
#include "Thief.h"


Thief::Thief(CLASS)
{
}


int Thief::atak()
{
	if (this->actualMana >= 65) {
		LIME; cout << "WBIJASZ PRZECIWNIKOWI NÓ¯ W PLECY!";
		this->actualMana -= 65;
		return attackValueMax + dex * 2;
	}
	else {
		LIME; cout << "NIE POSIADASZ WYSTARCZAJ¥CEJ ILOŒCI ENERGII! (65)";
		return 0;
	}
}

void Thief::lvlup()
{
	this->lvl++;
	this->st += 2;
	this->freeAbilityPoints += 2;
}

Thief::~Thief()
{
}
