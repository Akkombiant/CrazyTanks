#pragma once
#ifndef HERO_H
#define HERO_H
#include "tankBase.h"

class Hero : public tankBase {
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



#endif // !HERO_H
