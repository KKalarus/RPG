#include "pch.h"
#include "Map.h"



Map::Map()
{
	srand(time(NULL));
	int place = (rand() % 50)+1;
	if (place >= 1 && place <= 14) {
		this->place = MT_FOREST;
		if (rand() % 2 == 0) {
			this->enemy = false;
		}
		else {
			this->enemy = true;
		}
	}
	else if (place >= 15 && place <= 28) {
		this->place = MT_MOUNTAINS;
		if (rand() % 3 == 0) {
			this->enemy = false;
		}
		else {
			this->enemy = true;
		}
	}
	else if (place >= 29 && place <= 33) {
		this->place = MT_HOUSE;
		if (rand() % 6 == 0) {
			this->enemy = false;
		}
		else {
			this->enemy = true;
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
}

void Map::setCity() {
	this->place = MT_CITY;
}

int Map::getPlace() {
	return static_cast<int>(this->place);
}

void Map::visitPlace()
{
	this->visited = true;
}

Map::~Map()
{
}
