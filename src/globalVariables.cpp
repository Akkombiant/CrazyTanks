#include "globalVariables.h"
#include <cstdlib>

int wallCoordY, wallCoordX, eY = rand() % 21 + 2,
eX = rand() % 21, bulletY, bulletX, y, x, hY = 27, hX = 15;

float startTime;

int N = 1, S = 1, W = 1, E = 1;

char map[30][50] =
{ ' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ',
' ',' ',' ',' ',' ' };