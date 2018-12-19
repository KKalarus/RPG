#pragma once
enum TYPE {T_WEAPON, T_ARMOR, T_NECKLACE, T_RING, T_FREESPACE};

class Item
{
private:
	TYPE typ;
	
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
	int attStr;
	bool isEquiped = false;
public:
	Item();
	Item(TYPE);
	Item(TYPE,int,int,int,int,int,int,int,int,int,int,int);
	void showItem();
	~Item();
};

