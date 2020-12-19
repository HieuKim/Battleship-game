#pragma once
#include<fstream>
extern const int GridSize;
extern int CurrentPlayer;
extern int GameMode;
void PlaceShips(char** PlayerGrid, char** EnemyGrid, std::fstream& File);
