#include "Enemy.h"
#include "globalVariables.h"
#include "Hero.h"
#include <cstdlib>
Hero HERO;

int Enemy :: takeX() {
	return eX;
}

int Enemy :: takeY() {
	return eY;
}

void Enemy :: loadTank() {
	
	map[eY][eX] = 'E';
	map[eY][eX + 1] = '[';
	map[eY][eX - 1] = ']';
	map[eY - 1][eX] = 'I';
}

void Enemy :: turnUp() {
	if (map[eY - 3][eX] == ' ') {
		map[eY][eX] = ' ';
		map[eY][eX + 1] = ' ';
		map[eY][eX - 1] = ' ';
		map[eY - 1][eX] = ' ';
		map[eY + 1][eX] = ' ';

		eY -= 1;

		map[eY][eX] = 'E';
		map[eY][eX + 1] = '[';
		map[eY][eX - 1] = ']';
		map[eY - 1][eX] = 'I';
	}
}

void Enemy :: turnDown() {
	if (map[eY + 3][eX] == ' ') {
		map[eY][eX] = ' ';
		map[eY][eX + 1] = ' ';
		map[eY][eX - 1] = ' ';
		map[eY - 1][eX] = ' ';
		map[eY + 1][eX] = ' ';

		eY += 1;

		map[eY][eX] = 'E';
		map[eY][eX + 1] = '[';
		map[eY][eX - 1] = ']';
		map[eY + 1][eX] = 'I';
	}
}

void Enemy :: turnLeft() {
	if (map[eY][eX - 3] == ' ') {
		map[eY][eX] = ' ';
		map[eY][eX + 1] = ' ';
		map[eY][eX - 1] = ' ';
		map[eY - 1][eX] = ' ';
		map[eY + 1][eX] = ' ';

		eX -= 1;

		map[eY][eX] = 'E';
		map[eY + 1][eX] = '=';
		map[eY - 1][eX] = '=';
		map[eY][eX - 1] = '-';
	}
}

void Enemy :: turnRight() {
	if (map[eY][eX + 3] == ' ') {
		map[eY][eX] = ' ';
		map[eY][eX + 1] = ' ';
		map[eY][eX - 1] = ' ';
		map[eY - 1][eX] = ' ';
		map[eY + 1][eX] = ' ';

		eX += 1;

		map[eY][eX] = 'E';
		map[eY + 1][eX] = '=';
		map[eY - 1][eX] = '=';
		map[eY][eX + 1] = '-';
	}
}

void Enemy :: control() {
	if (HERO.takeX() > takeX() && HERO.takeY() > takeY())
	{
		if (map[eY + 3][eX] == ' ') {
			turnDown();
		}
	}
	else if (HERO.takeX() > takeX() && HERO.takeY() < takeY())
	{
		if (map[eY - 3][eX] == ' ') {
			turnUp();
		}
	}
	else if (HERO.takeX() < takeX() && HERO.takeY() > takeY())
	{
		if (map[eY + 3][eX] == ' ') {
			turnDown();
		}
	}
	else if (HERO.takeX() < takeX() && HERO.takeY() < takeY())
	{
		if (map[eY - 3][eX] == ' ') {
			turnUp();
		}
	}
	else if (HERO.takeX() == takeX() && HERO.takeY() > takeY())
	{
		if (map[eY + 3][eX] == ' ') {
			turnDown();
		}
	}
	else if (HERO.takeX() == takeX() && HERO.takeY() < takeY())
	{
		if (map[eY - 3][eX] == ' ') {
			turnUp();
		}
	}
	else if (HERO.takeX() > takeX() && HERO.takeY() == takeY())
	{
		if (map[eY][eX + 3] == ' ') {
			turnRight();
		}
	}
	else if (HERO.takeX() < takeX() && HERO.takeY() == takeY())
	{
		if (map[eY][eX - 3] == ' ') {
			turnLeft();
		}
	}
}

void Enemy :: createBullet(){}