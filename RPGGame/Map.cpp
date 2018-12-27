#include "pch.h"
#include "Map.h"
#include <random>
#include <chrono>

Map::Map()
{
}

void Map::setCity() {
	this->place = MT_CITY;
}

void Map::setPlace() {
	std::mt19937 rng;
	rng.seed(std::random_device()());
	std::uniform_int_distribution<std::mt19937::result_type> placer(1, 50);
	std::uniform_int_distribution<std::mt19937::result_type> monsterr(1, 6);
	std::uniform_int_distribution<std::mt19937::result_type> chestrr(1, 2);
	int place = placer(rng);
	int monster = monsterr(rng);
	int chestr = chestrr(rng);
	cout << "MIEJCE " << place;
	if (place >= 1 && place <= 14) {
		this->place = MT_FOREST;
		if (monster%2==0) {
			this->enemy = false;
		}
		else {
			this->enemy = true;
		}
	}
	else if (place >= 15 && place <= 28) {
		this->place = MT_MOUNTAINS;
		if (monster%3==0) {
			this->enemy = true;
		}
		else {
			this->enemy = false;
		}
	}
	else if (place >= 29 && place <= 33) {
		this->place = MT_HOUSE;
		if (monster==6) {
			this->enemy = true;
		}
		else {
			this->enemy = false;
		}
	}
	else if (place >= 34 && place <= 47) {
		this->place = MT_CAVE;
		this->enemy = true;
	}
	else if (place >= 48 && place <= 50) {
		this->place = MT_CITY;
		this->enemy = false;
	}

	if(chestr==1) this->chest = true;
	else this->chest = false;

}

int Map::getPlace() {
	return static_cast<int>(this->place);
}

bool Map::isChest() {
	return this->chest;
}
bool Map::isEnemy() {
	return this->enemy;
}
void Map::visitPlace()
{
	this->visited = true;
}

Map::~Map()
{
}
