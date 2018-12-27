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
	void drawGUI(Postac*); //Draws basic GUI outlines with values
	void CharOptions(Postac * character); //Opcje gracza - poruszanie sie, EQ itd.
	void updateStats(Postac*); //Updates stats tab
	void drawEQ(Postac*); //Lets you use your equipment (browse, choose items, equip etc)
	~GUI();
};

