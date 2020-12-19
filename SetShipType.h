#pragma once
#include<string>
#include<fstream>
extern int CurrentPlayer;
extern int GameMode;
extern std::string Player1Name;
extern std::string Player2Name;
void SetShipType(int& iCurrentShip, int& iShipBeingPlaced, std::string& sShipName, char& cShipChar, char** EnemyGrid);