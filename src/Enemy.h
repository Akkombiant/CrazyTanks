#pragma once
#ifndef ENEMY_H
#define ENEMY_H
#include "tankBase.h"

class Enemy : public tankBase {
public:

	int takeX();

	int takeY();

	void loadTank();

	void createBullet();

	void control();

private:

	void turnUp();

	void turnDown();

	void turnLeft();

	void turnRight();
};


#endif // !ENEMY_H
