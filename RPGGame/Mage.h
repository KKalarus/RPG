#pragma once
#include "Postac.h"

class Mage :public Postac
{
public:
	Mage(CLASS);
	void atak();
	void lvlup();
	~Mage();
};

