#include "pch.h"
#include "Shaman.h"


Shaman::Shaman(CLASS)
{
}


void Shaman::atak()
{
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
