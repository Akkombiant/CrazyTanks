#pragma once
#ifndef MAP_H
#define MAP_H

class Map {
private:

	void createMap();

	void createBase();

	void createWall();

public:
	bool status = false;

	void clearScreen();

	void loadMap();

	//void runTimer();

	//void killedEnemies();
};

#endif