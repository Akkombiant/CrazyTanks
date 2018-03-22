#pragma once
#ifndef TANKBASE_H
#define TANKBASE_H

class tankBase {
public:

	virtual void loadTank() = 0;

	virtual void turnUp() = 0;

	virtual void turnDown() = 0;

	virtual void turnLeft() = 0;

	virtual void turnRight() = 0;

	virtual void createBullet() = 0;

	virtual void control() = 0;
};


#endif // !TANKBASE_H
