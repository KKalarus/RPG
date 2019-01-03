#include "pch.h"
#include "Warrior.h"

Warrior::Warrior(CLASS)
{
}

void Warrior::atak()
{
	cout << "Warrior atakuje";
}

void Warrior::lvlup()
{
	this->lvl++;
	this->str += 2;
}


Warrior::~Warrior()
{
}
