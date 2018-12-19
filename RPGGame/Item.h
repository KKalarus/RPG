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
	bool isEquiped = false;
public:
	Item();
	Item(TYPE);
	Item(TYPE,int,string,int,int,int,int,int,int,int,int,int,int,int,QUALITY);
	TYPE getType();
	void showItem(int);
	~Item();
};

