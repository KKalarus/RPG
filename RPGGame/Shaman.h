#pragma once
#include "Postac.h"
class Shaman :public Postac
{
public:
	Shaman(CLASS);
	void atak();
	void lvlup();
	~Shaman();
};

