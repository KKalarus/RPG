#pragma once
#include "Item.h"
#include "Map.h"

enum CLASS {C_WARRIOR, C_ARCHER, C_MAGE, C_THIEF, C_SHAMAN};
enum RACE {R_HUMAN, R_ELF, R_DWARF, R_HOBBIT, R_ORC};
class Postac
{
private:
	int playerX = 20, playerY = 20; //Ustawia gracza na koordynatach 11,11 - GLOWNE MIASTO.

	Map mapka[21][21]; //Generuje mape 21/21 pól.
	CLASS klasa;
	RACE rasa;

	int str; //SILA
	int dex; //ZWINNOSC
	int st; //STAMINA (WYTRZYMALOSC)
	int in; //INTELIGENCJA
	int lu; //SZCZESCIE

	int hp = 90 + st * 10; //¯ycie gracza. Bazowe 90 + 10pkt za ka¿dy punkt StAMINY.
	int mana = 60 + in * 12; //Mana gracza. Bazowo 60 + 12pkt za ka¿dy pkt inteligencji.
	int attackValueMin = 1; //Minimalna wartoœæ ataku - 1, zwiêkszana dziêki broni / itemkom. SILA NIE MA NA TO WPLYWU
	int attackValueMax = 3 + str; // MAKSYMALNA wartoœæ ataku - 3 + punkty si³y + ITEMKI ZA£OZONE.
	int armor = 0; //ARMOR
	string name; //IMIE POSTACI

	int money = 0; // Pieni¹dze gracza
	Item eq[15]; //MIEJSCA W EQ
	int hPotions = 0; // Health potions
	int mPotions = 0; //Mana Potions
	int lvl=0; //AKTUALNY LVL
	int lvlmax; //MAX LVL POSTACI
	int xp=0; //Aktualny XP
	int freeAbilityPoints; //WOLNE PUNKTY UMIEJETNOSCI

public:
	Postac();

	void showmap(Map *);
	Map* mapPointer = *mapka;
	CLASS chooseClass(); //Wybor klasy postaci
	void setClass(CLASS); //Sets class
	CLASS getClass();
	int getActualPlace();
	int getMana();
	int getMoney();
	int getPlayerX();
	int getPlayerY();
	void chooseRace(); // Wybor rasy
	RACE getRace();
	void chooseName(); // Wybor nicku
	string getName();
	void buildCharacter(); //Budowanie gracza, tj. ustawienie pierwszych wartosci umiejetnosci dla postaci.
	void showEq(int); //Shows item in [i] place in EQ
	void initializeEq();//Sets all EQ spaces as free
	void addItem(Item item);
	int getXp();
	int getLvl();

	int getStr();
	int getDex();
	int getSt();
	int getIn();
	int getLu();

	int getHPotions();

	int getMPotions();

	int getHP();

	int getMinAttack();

	int getMaxAttack();

	int getArmor();

	bool visit();

	void fight(); //Fight with enemy :D

	void openChest(); // Opens chest, adds item to inventory! :D

	void equipItem(int item);

	virtual void atak() = 0; //Atak dla kazdej postaci osobno.
	virtual void lvlup() = 0; //LVLUp doda okresone umki, w zaleznosci od klasy.

	~Postac();
	void moveStar();
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
};