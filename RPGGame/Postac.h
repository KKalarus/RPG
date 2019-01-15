#pragma once
#include "Item.h"
#include "Map.h"
#include "Enemy.h"

enum CLASS {C_WARRIOR, C_ARCHER, C_MAGE, C_THIEF, C_SHAMAN};
enum RACE {R_HUMAN, R_ELF, R_DWARF, R_HOBBIT, R_ORC};
class Postac
{
protected:
	int playerX = 20, playerY = 20; //Ustawia gracza na koordynatach 11,11 - GLOWNE MIASTO.

	Map mapka[21][21]; //Generuje mape 21/21 pól.
	CLASS klasa;
	RACE rasa;

	int str; //SILA
	int dex; //ZWINNOSC
	int st; //STAMINA (WYTRZYMALOSC)
	int in; //INTELIGENCJA
	int lu; //SZCZESCIE

	int actualHp; //Aktualne ¿cyie
	int actualMana; //Aktualna mana

	int hp = 90 + st * 10; //¯ycie gracza. Bazowe 90 + 10pkt za ka¿dy punkt StAMINY.
	int mana = 60 + in * 12; //Mana gracza. Bazowo 60 + 12pkt za ka¿dy pkt inteligencji.
	int attackValueMin = 1; //Minimalna wartoœæ ataku - 1, zwiêkszana dziêki broni / itemkom. SILA NIE MA NA TO WPLYWU
	int attackValueMax = 3 + str; // MAKSYMALNA wartoœæ ataku - 3 + punkty si³y + ITEMKI ZA£OZONE.
	int armor = 0; //ARMOR
	string name; //IMIE POSTACI

	int money = 0; // Pieni¹dze gracza
	Item eq[15]; //MIEJSCA W EQ
#if debug==1
	int hPotions = 8; // Health potions
	int mPotions = 8; //Mana Potions
#endif
#if debug==0
	int hPotions = 6; // Health potions
	int mPotions = 4; //Mana Potions
#endif
	int lvl=1; //AKTUALNY LVL
	int lvlmax; //MAX LVL POSTACI, ale idk czy dodawaæ.
	int xp=0; //Aktualny XP
	int neededXP = 10 * lvl * sqrt(lvl);
	int freeAbilityPoints; //WOLNE PUNKTY UMIEJETNOSCI

	bool dead = false; //Czy umar³eœ? :D
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
	void addXp(int xp); //adds XP to character, chcecks for lvlup
	void initializeEq();//Sets all EQ spaces as free
	void addItem(Item item);
	int getXp();
	int getNextXp();
	int getLvl();

	int getStr();
	int getDex();
	int getSt();
	int getIn();
	int getLu();

	void modifyStr(int);
	void modifyDex(int);
	void modifySt(int);
	void modifyIn(int);
	void modifyLu(int);

	void modifyFreePoints(int points);

	int getHPotions();

	int getMPotions();

	int getHP();

	int getActualHP();

	int getActualMana();

	int getMinAttack();

	int getMaxAttack();

	int getArmor();

	bool visit();

	bool runAway();

	int dealDamage(); //Gets amount of DMG to deal to Enemy

	bool getDamage(int); //Gets damage
	bool dodge();//dodges
	bool checkDeath(); //You lost??
	bool crit(); //Critical hit?
	bool visit2();

	void walka(Enemy); //Actual fight

	void fight(Enemy); //Fight GUI

	void openChest(); // Opens chest, adds item to inventory! :D

	void equipItem(int item); // equips item

	void dropItem(int);

	void openShop();

	void sklepKupSprzedaj(int);

	int getFreePoints(); //Returns free ability points

	virtual int atak() = 0; //Atak dla kazdej postaci osobno.
	virtual void lvlup() = 0; //LVLUp doda okresone umki, w zaleznosci od klasy.

	int drinkMP(); //Drinks mana potion
	int drinkHP(); //Drinks HP Potion
	~Postac();
	void moveStar();
	bool moveUp();
	bool moveDown();
	bool moveLeft();
	bool moveRight();
};