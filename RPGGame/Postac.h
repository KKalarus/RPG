#pragma once
#include "Item.h"
enum CLASS {C_WARRIOR, C_ARCHER, C_MAGE, C_THIEF, C_SHAMAN};
enum RACE {R_HUMAN, R_ELF, R_DWARF, R_HOBBIT, R_ORC};
class Postac
{
private:
	CLASS klasa;
	RACE rasa;

	int str; //SILA
	int dex; //ZWINNOSC
	int st; //STAMINA (WYTRZYMALOSC)
	int in; //INTELIGENCJA
	int lu; //SZCZESCIE

	string name; //IMIE POSTACI

	int money;
	Item eq[15]; //MIEJSCA W EQ
	int lvl=0; //AKTUALNY LVL
	int lvlmax; //MAX LVL POSTACI
	int xp=0; //Aktualny XP
	int freeAbilityPoints; //WOLNE PUNKTY UMIEJETNOSCI

public:
	Postac();

	CLASS chooseClass(); //Wybor klasy postaci
	void setClass(CLASS); //Sets class
	CLASS getClass();
	void chooseRace(); // Wybor rasy
	RACE getRace();
	void chooseName(); // Wybor nicku
	string getName();
	void buildCharacter(); //Budowanie gracza, tj. ustawienie pierwszych wartosci umiejetnosci dla postaci.
	void showEq(); //Shows EQ
	void initializeEq();//Ustaw eq na puste
	int getXp();
	int getLvl();
	virtual void atak() = 0; //Atak dla kazdej postaci osobno.
	virtual void lvlup() = 0; //LVLUp doda okresone umki, w zaleznosci od klasy.

	~Postac();
};