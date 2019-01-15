#pragma once
#include "Postac.h"

class Mage :public Postac
{
public:
	Mage(CLASS);
	int atak();
	void lvlup();
	~Mage();
};

