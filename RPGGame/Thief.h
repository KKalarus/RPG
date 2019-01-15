#pragma once
#include "Postac.h"

class Thief :public Postac
{
public:
	Thief(CLASS);
	int atak();
	void lvlup();
	~Thief();
};

