#include "pch.h"
#include "Archer.h"


Archer::Archer(CLASS)
{
}

void Archer::atak()
{
	cout << "Archer atakuje";
}

void Archer::lvlup()
{
	this->lvl++;
	this->dex += 2;
}


Archer::~Archer()
{
}
