#pragma once
#include<string>
extern std::string Player1Name;
extern std::string Player2Name;
extern const int GridSize; // A constant holding size of all arrays
extern int rocket1;
extern int score1;
extern int score2;
extern int rocket2;
extern int GameMode; // Holds data on if the player is playing a human 
extern int P1ShipHealth[5];
extern int CurrentPlayer;
extern int P2ShipHealth[5];
void playerShooting(char** acBoard, char** acHits, char** acDmgBoard, bool* GameEnd);
