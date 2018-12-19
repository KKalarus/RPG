#pragma once
#include "pch.h"
#include <iostream>
//#include "Postac.h"
#include <Windows.h>
#include <conio.h>
#include "Warrior.h"
#include "Dialogi.h"
#include "Archer.h"
#include "Mage.h"
#include "Thief.h"
#include "Shaman.h"

Postac *postac;
CLASS klasa;
RACE rasa;
Postac **pointer = &postac;
Warrior warrior(static_cast<CLASS>(0));
Archer archer(static_cast<CLASS>(1));
Mage mage(static_cast<CLASS>(2));
Thief thief(static_cast<CLASS>(3));
Shaman shaman(static_cast<CLASS>(4));