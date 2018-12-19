#pragma once
#include "Postac.h"

class Thief :public Postac
{
public:
	Thief(CLASS);
	void atak();
	void lvlup();
	~Thief();
};

