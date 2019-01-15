#pragma once
#include "Postac.h"
class Shaman :public Postac
{
public:
	Shaman(CLASS);
	int atak();
	void lvlup();
	~Shaman();
};

