#pragma once
enum MAPTYPE {MT_FOREST, MT_MOUNTAINS, MT_HOUSE, MT_CAVE, MT_CITY};
class Map
{
private:
	MAPTYPE place;
	bool chest;
	bool enemy;
	bool visited = false;
public:
	Map();
	void setCity();
	int getPlace();
	void visitPlace();
	~Map();
};

