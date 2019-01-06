#pragma once
enum LOOK {L_ORC, L_SKELETON, L_THIEF, L_DELF};
class Enemy
{
private:
	int health;
	int actualHealth;
	int damage;
	int damageMin;
	int dodgeChance;
	int runAwayChance;
	int armor;
	bool dropsItem;
	LOOK look;
public:
	Enemy();
	Enemy(int, int, int, int, int, LOOK,bool); //Generates enemy - health,armor ,dmg,dodge,runAway, itemDrop
	Enemy generateRandomEnemy(int);
	int attack();
	bool runAway();
	bool dodge();
	bool tryToRun();
	~Enemy();
};

