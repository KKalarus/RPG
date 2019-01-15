#pragma once
#include "Postac.h"

class Archer :public Postac
{
public:
	Archer(CLASS);
	int atak();
	void lvlup();
	~Archer();
};
