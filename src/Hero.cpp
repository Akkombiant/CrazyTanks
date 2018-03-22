#include "Hero.h"
#include "globalVariables.h"
#include <conio.h>
#include <Windows.h>

int Hero :: takeX() {
	return hX;
}

int Hero :: takeY() {
	return hY;
}

void Hero::loadTank() {
		
		map[hY][hX] = 'X';
		map[hY][hX + 1] = '|';
		map[hY][hX - 1] = '|';
		map[hY - 1][hX] = 'I';
	
}

void Hero :: turnUp() {

	map[hY][hX] = ' ';
	map[hY][hX + 1] = ' ';
	map[hY][hX - 1] = ' ';
	map[hY - 1][hX] = ' ';
	map[hY + 1][hX] = ' ';

	hY -= 2;

	map[hY][hX] = 'X';
	map[hY][hX - 1] = '|';
	map[hY][hX + 1] = '|';
	map[hY - 1][hX] = 'I';
}

void Hero :: turnDown() {
	map[hY][hX] = ' ';
	map[hY][hX + 1] = ' ';
	map[hY][hX - 1] = ' ';
	map[hY - 1][hX] = ' ';
	map[hY + 1][hX] = ' ';

	hY += 2;

	map[hY][hX] = 'X';
	map[hY][hX - 1] = '|';
	map[hY][hX + 1] = '|';
	map[hY + 1][hX] = 'I';
}

void Hero :: turnLeft() {
	map[hY][hX] = ' ';
	map[hY][hX + 1] = ' ';
	map[hY][hX - 1] = ' ';
	map[hY - 1][hX] = ' ';
	map[hY + 1][hX] = ' ';

	hX -= 2;

	map[hY][hX] = 'X';
	map[hY - 1][hX] = '=';
	map[hY + 1][hX] = '=';
	map[hY][hX - 1] = '-';
}

void Hero :: turnRight() {
	map[hY][hX] = ' ';
	map[hY][hX + 1] = ' ';
	map[hY][hX - 1] = ' ';
	map[hY - 1][hX] = ' ';
	map[hY + 1][hX] = ' ';

	hX += 2;

	map[hY][hX] = 'X';
	map[hY + 1][hX] = '=';
	map[hY - 1][hX] = '=';
	map[hY][hX + 1] = '-';
}

void Hero :: createBullet() {
	bulletY = takeY();
	bulletX = takeX();
	if (map[hY - 1][hX] == 'I') { //shot up
		map[bulletY - 2][bulletX] = 'o';
		N = 0;
	}
	else if (map[hY + 1][hX] == 'I') { //shot down
		map[bulletY + 2][bulletX] = 'o';
		S = 0;
	}
	else if (map[hY][hX - 1] == '-') {  //shot left
		map[bulletY][bulletX - 2] = 'o';
		W = 0;
	}
	else if (map[hY][hX + 1] == '-') {  //shot right
		map[bulletY][bulletX + 2] = 'o';
		E = 0;
	}
	/*if (map[bulletY - 1][bulletX] == ' ') {
		map[bulletY + 1][bulletX] = ' ';
		bulletY -= 1;
		if (map[bulletY - 2][bulletX] == ' ') {
			map[bulletY][bulletX] = 'o';
		}
		else {
			map[bulletY + 1][bulletX] = ' '; N = 1;
		}
	}*/
}

void Hero::control() {
	if (_kbhit()) {
		switch (_getch())
		{
		case 32:
			createBullet();
			break;
		case 72:   //up
			if (map[hY - 3][hX] == ' ')
				turnUp();
			break;
		case 75: //left
			if (map[hY][hX - 3] == ' ')
				turnLeft();
			break;
		case 77: //right
			if (map[hY][hX + 3] == ' ')
				turnRight();
			break;
		case 80: //down
			if (map[hY + 3][hX] == ' ')
				turnDown();
			break;
		default:
			break;
		}
	}
}