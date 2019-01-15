#include "pch.h"
#include "Mage.h"


Mage::Mage(CLASS)
{
}

int Mage::atak()
{
	if (this->actualMana >= 100) {
		LIME; cout << "CASTUJESZ FIREBALLA W PRZECIWNIKA!";
		this->actualMana -= 100;
		return in * 10;
	}
	else {
		LIME; cout << "NIE POSIADASZ WYSTARCZAJ¥CEJ ILOŒCI ENERGII! (100)";
		return 0;
	}
}

void Mage::lvlup()
{
	this->lvl++;
	this->in += 2;
	this->freeAbilityPoints += 2;
}


Mage::~Mage()
{
}
