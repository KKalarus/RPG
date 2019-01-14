#include "pch.h"
#include "Thief.h"


Thief::Thief(CLASS)
{
}


void Thief::atak()
{
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
