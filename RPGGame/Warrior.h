#pragma once
#include "Postac.h"

class Warrior :public Postac
{
public:
	Warrior(CLASS);
	void atak();
	void lvlup();
	~Warrior();
};

