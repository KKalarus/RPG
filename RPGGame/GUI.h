#pragma once
#include "Warrior.h"
#include "Archer.h"
#include "Mage.h"
#include "Thief.h"
#include "Shaman.h"
class GUI
{
private:
public:
	GUI();
	void intro(Postac**, Warrior&, Archer&, Mage&, Thief&, Shaman&); //Starts intro, makes character, chooses class, name, let's you spend free ability points for first time
	void drawGUI(Postac *character); //Draws basic GUI outlines with values
	~GUI();
};

