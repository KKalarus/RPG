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


void Enemy::generateRandomEnemy(int playerLevel, int playerAttack)
{
	std::mt19937 rng;
	rng.seed(std::random_device()());

	std::uniform_int_distribution<std::mt19937::result_type> attackBoostr(1, (playerLevel/3)<1?1: playerLevel / 3);
	std::uniform_int_distribution<std::mt19937::result_type> dropRand(0,1);
	std::uniform_int_distribution<std::mt19937::result_type> lookRand(0,3);

	int skillPoints = playerLevel * 5 + 8;
	LOOK look = static_cast<LOOK>(lookRand(rng));
	int hpPoints;
	int dodgePoints;
	int runAwayPoints;
	int armor;
	int damage;
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
	this->health = hpPoints * 10;
	this->actualHealth = hpPoints * 10;
	this->armor = armor;
	this->damageMax = damage;
	this->damageMin = damageMin;
	this->dodgeChance = dodgePoints * 0.5;
	this->runAwayChance = runAwayPoints;
	this->look = look;
	this->dropsItem = dropsItem;
	if (this->damageMin > playerAttack) {
		this->damageMin = playerAttack / 2;
	}
}

int Enemy::attack() {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> damagePoints(this->damageMin, this->damageMax);
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
		if (this->actualHealth < 0)this->actualHealth = 0;
		if (checkDeath()) {
			//drop item
		}
		return true;
	}
}
bool Enemy::runOrFight() {
	if (this->actualHealth < this->health / 4) {
		std::mt19937 rng;
		rng.seed(std::random_device()());
		std::uniform_int_distribution<std::mt19937::result_type> decisionRand(0, 2);
		if (decisionRand(rng) == 2) {
			return true;
		}
		else return false;
	}
	else return false;
}
LOOK Enemy::getLook()
{
	return this->look;
}

bool Enemy::isDead()
{
	return isdead;
}

int Enemy::getHP()
{
	return this->actualHealth;
}
int Enemy::getMaxHP()
{
	return this->health;
}
int Enemy::dropHP()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> HPRand(0, 4);
	return HPRand(rng);
}
int Enemy::dropMP()
{
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> MPRand(0, 4);
	return MPRand(rng);
}
int Enemy::dropGold(int lvl) {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> GoldRand(1, lvl*10);
	return GoldRand(rng);
}
int Enemy::getArmor() {
	return armor;
}
Enemy::~Enemy()
{
}
