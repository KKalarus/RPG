#pragma once
enum LOOK {L_ORC, L_SKELETON, L_THIEF, L_DELF};
class Enemy
{
private:
	int health;
	int actualHealth;
	int damageMax;
	int damageMin;
	int dodgeChance;
	int runAwayChance;
	int armor;
	bool dropsItem;
	bool isdead = false;
	LOOK look;
public:
	Enemy();
	Enemy(int, int, int, int, int, LOOK,bool); //Generates enemy - health,armor ,dmg,dodge,runAway, itemDrop
	void generateRandomEnemy(int,int); //Makes random enemy
	int attack(); // Attack player
	bool runAway(); //Do we need to run?
	bool dodge(); //Dodges!
	bool tryToRun(); //We need to run. NOW
	bool checkDeath(); //Is dead?
	bool getDamage(int); //Ouch this hurt
	bool runOrFight(); //Name is the key to this one
	LOOK getLook(); //Gets enemy look, nothing serious
	bool isDead(); //DELETE THIS
	int getHP(); //Gets HP in THIS moment
	int getMaxHP(); //MAX HP
	int dropHP();
	int dropMP();
	int dropGold(int lvl);
	int getArmor();
	~Enemy();
};

