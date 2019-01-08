#include "pch.h"
#include "Enemy.h"
#include "Item.h"
#include <random>

Enemy::Enemy()
{
}

Enemy::Enemy(int hp, int armor, int damage, int dodge, int runAway, LOOK look, bool dropsItem)
{

}


Enemy Enemy::generateRandomEnemy(int playerLevel)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());

	std::uniform_int_distribution<std::mt19937::result_type> attackBoostr(1, playerLevel);
	std::uniform_int_distribution<std::mt19937::result_type> dropRand(0,1);
	std::uniform_int_distribution<std::mt19937::result_type> lookRand(0,3);

	int skillPoints = playerLevel * 5 + 15;
	LOOK look = static_cast<LOOK>(lookRand(rng));
	int hpPoints;
	int dodgePoints;
	int runAwayPoints;
	int armor;
	bool dropsItem = static_cast<bool>(dropRand(rng));

	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> randhPoints(1, skillPoints-2);

	hpPoints = randhPoints(rng);
	skillPoints -= hpPoints;

	std::uniform_int_distribution<std::mt19937::result_type> randdPoints(1, skillPoints - 1);
	dodgePoints = randdPoints(rng);
	skillPoints -= dodgePoints;
	runAwayPoints = skillPoints;
	if (runAwayPoints > 100) runAwayPoints = 100;
	if (dodgePoints > 200) dodgePoints = 200;
	Item x;
	do {
		x = x.generateRandomItem(playerLevel);
	} while (x.getType() != T_WEAPON);
	damage = x.getAttStr() + attackBoostr(rng) + 1;
	damageMin = x.getAttStr();
	do {
		x = x.generateRandomItem(playerLevel);
	} while (x.getType() != T_ARMOR);
	armor = x.getArmor() + attackBoostr(rng) + 1;
	actualHealth = hpPoints * 10;
	return Enemy(hpPoints * 10, armor, damage, dodgePoints * 0.5, runAwayPoints, look, dropsItem);
}

int Enemy::attack() {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> damagePoints(this->damageMin, this->damage);
	return(damagePoints(rng));
}

bool Enemy::runAway() {

	int chance = chanceR();
	if (chance <= runAwayChance) return true;
	else return false;
}

bool Enemy::dodge() {

	int chance = chanceR();
	if (chance <=dodgeChance) return true;
	else return false;
}
bool Enemy::tryToRun() {
	int chance = chanceR();
	int toRun = actualHealth / health * 100;
	if (chance <= toRun) return true;
	else return false;
}

bool Enemy::checkDeath()
{
	if (this->actualHealth <= 0) {
		this->isdead = true;
		return true;
	}
	else return false;
}

bool Enemy::getDamage(int dmg)
{
	if (dodge()) return false;
	else {
		this->actualHealth -= dmg;
		if (checkDeath()) {
			//drop item
		}
		return true;
	}
}

LOOK Enemy::getLook()
{
	return LOOK();
}

bool Enemy::isDead()
{
	return isdead;
}

Enemy::~Enemy()
{
}
