#pragma once
enum MAPTYPE {MT_FOREST, MT_MOUNTAINS, MT_HOUSE, MT_CAVE, MT_CITY};
class Map
{
private:
	MAPTYPE place;
	bool chest;
	bool enemy;
	bool wasEnemy;
	bool visited = false;
public:
	Map();
	void setCity();
	void setPlace();
	void openChest();
	int getPlace();
	bool isChest();
	bool isEnemy();
	void killEnemy();
	void visitPlace();
	~Map();
};

