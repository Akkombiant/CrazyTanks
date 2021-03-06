#include "Map.h"
#include "Hero.h"
#include "Enemy.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <chrono>

int main()
{
	auto start = std::chrono::high_resolution_clock::now();
	auto stop = start;
	start = std::chrono::high_resolution_clock::now();
	Map MAP;
	Hero HERO;
	Enemy ENEMY;
	//HERO.loadTank();
	ENEMY.loadTank();
	Sleep(10);
	while (true) {
		MAP.loadMap();
		MAP.clearScreen();
		HERO.control();
		

		ENEMY.control();
		stop = std::chrono::high_resolution_clock::now();
		std::cout << "\nTime: " << std::chrono::duration_cast<std::chrono::seconds>(stop - start).count()
			<< " seconds\n";
	}
	_getch();
    return 0;
}

