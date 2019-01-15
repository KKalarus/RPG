#pragma once
#include "Postac.h"

class Warrior :public Postac
{
public:
	Warrior(CLASS);
	int atak();
	void lvlup();
	~Warrior();
};

