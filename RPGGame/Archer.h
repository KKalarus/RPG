#pragma once
#include "Postac.h"

class Archer :public Postac
{
public:
	Archer(CLASS);
	void atak();
	void lvlup();
	~Archer();
};
