#pragma once
//#include "Postac.h"
enum TYPE {T_WEAPON, T_ARMOR, T_NECKLACE, T_RING, T_FREESPACE};
enum QUALITY {Q_LEGENDARY, Q_RARE, Q_COMMON, Q_TRASH};
class Item
{
private:
	TYPE typ;
	QUALITY quality;
	int forWho; //CLASS ID

	string itemName;

	int needStr;
	int needDex;
	int needIn;
	int needSt;
	int needLu;

	int giveStr;
	int giveDex;
	int giveIn;
	int giveSt;
	int giveLu;
	
	//CLASS needClass;
	int attStr; //Wartoœæ ataku zadawanego przez broñ
	int armor;

	bool isEquiped = false;
public:
	Item();
	Item(TYPE);
	Item(TYPE,int,string,int,int,int,int,int,int,int,int,int,int,int,int,QUALITY); //Typ przedmiotu, dla kogo, nazwa, wymagana: sila, zrecznosc, inteligencja, wytrzymalosc, szczescie DAWANE: sila, zrecznosc, inta, wytrzymalosc, szczescie, atak, armor, jakosc
	TYPE getType();
	void showItem(int);

	int getGStr();
	int getNStr();
	int getGDex();
	int getNDex();
	int getGIn();
	int getNIn();
	int getGSt();
	int getNSt();
	int getGLu();
	int getNLu();
	int getClass();
	int getAttStr();
	int getArmor();

	void equip();
	void takeOff();
	bool isItemEquiped();
	~Item();
};

