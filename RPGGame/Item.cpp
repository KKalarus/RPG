#include "pch.h"
#include "Item.h"

Item::Item()
{
}

Item::Item(TYPE typ) {
	if (typ == T_FREESPACE) {
		this->typ = typ;
		this->needStr = 0;
		this->needDex = 0;
		this->needIn = 0;
		this->needSt = 0;
		this->needLu = 0;

		this->giveStr = 0;
		this->giveDex = 0;
		this->giveIn = 0;
		this->giveSt = 0;
		this->giveLu = 0;
	}
	else {
		Item(T_FREESPACE);
	}
}
Item::Item(TYPE typ, int attStr, int needStr, int needDex, int needIn, int needSt, int needLu, int giveStr, int giveDex, int giveIn, int giveSt, int giveLu)
{
	this->typ = typ;

	this->needStr = needStr;
	this->needDex = needDex;
	this->needIn = needIn;
	this->needSt = needSt;
	this->needLu = needLu;

	this->giveStr = giveStr;
	this->giveDex = giveDex;
	this->giveIn = giveIn;
	this->giveSt = giveSt;
	this->giveLu = giveLu;

}

void Item::showItem() {
	cout << "Typ przedmiotu : " << this->typ;
	cout << "Potrzebna sila : " << this->needStr;
	cout << endl;
	cout << "Potrzebna zwinnosc : " << this->needDex;
}

Item::~Item()
{
}
