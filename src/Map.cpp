#include "Map.h"
#include "globalVariables.h"
#include <iostream>
#include <windows.h>

void Map :: createMap() {
	for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 50; j++) {
			map[i][0] = '|';
			map[i][48] = '|';
			map[i][j] = ' ';
			map[0][j] = '-';
			map[29][j] = '-';
		}
	}
}

void Map :: createWall() {
	for (int i = 0; i < 7; i++) {
		wallCoordX = rand() % 50;
		wallCoordY = rand() % 30;
		if (i <= 2) {
			map[wallCoordY][wallCoordX] = 219;
			map[wallCoordY][wallCoordX + 1] = 219;
			map[wallCoordY][wallCoordX - 1] = 219;
			map[wallCoordY + 1][wallCoordX - 1] = 219;
			map[wallCoordY + 1][wallCoordX + 1] = 219;
			map[wallCoordY - 1][wallCoordX - 1] = 219;
			map[wallCoordY - 1][wallCoordX + 1] = 219;
			map[wallCoordY + 1][wallCoordX] = 219;
			map[wallCoordY - 1][wallCoordX] = 219;
		}
		else if (i > 2) {
			map[wallCoordY][wallCoordX] = 219;
			map[wallCoordY][wallCoordX + 1] = 219;
			map[wallCoordY][wallCoordX + 2] = 219;
			map[wallCoordY][wallCoordX + 3] = 219;
			map[wallCoordY][wallCoordX - 1] = 219;
			map[wallCoordY + 1][wallCoordX - 1] = 219;
			map[wallCoordY + 1][wallCoordX + 1] = 219;
			map[wallCoordY + 1][wallCoordX + 2] = 219;
			map[wallCoordY + 1][wallCoordX + 3] = 219;
			map[wallCoordY - 1][wallCoordX - 1] = 219;
			map[wallCoordY - 1][wallCoordX + 1] = 219;
			map[wallCoordY - 1][wallCoordX + 2] = 219;
			map[wallCoordY - 1][wallCoordX + 3] = 219;
			map[wallCoordY + 1][wallCoordX] = 219;
			map[wallCoordY - 1][wallCoordX] = 219;
		}
	}
}

void Map::createBase() {
	y = 27; x = 23;
	map[y][x] = '$';
	map[y][x - 1] = 219;
	map[y][x - 2] = 219;
	map[y][x + 1] = 219;
	map[y][x + 2] = 219;
	map[y - 1][x] = 219;
	map[y - 2][x] = 219;
	map[y - 1][x - 1] = 219;
	map[y - 2][x - 2] = 219;
	map[y - 1][x - 2] = 219;
	map[y - 2][x - 1] = 219;
	map[y - 1][x + 1] = 219;
	map[y - 2][x + 1] = 219;
	map[y - 1][x + 2] = 219;
	map[y - 2][x + 2] = 219;
}

void Map::loadMap() {
	if (status == false) {
		createMap();
		createBase();
		createWall();
		status = true;
	}
	for (int i(0); i < 30; i++) {
		for (int j(0); j < 50; j++) {
			std::cout << map[i][j];
			if (j >= 49) {
				std::cout << std::endl;
			}
		}
	}
}

void Map :: clearScreen() {
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);

	Position.X = 0;
	Position.Y = 0;
	SetConsoleCursorPosition(hOut, Position);
}