#include"SetShipType.h"
#include"drawBoard.h"
#include<string>
#include<iostream>
using namespace std;
extern int CurrentPlayer;
extern int GameMode;
extern string Player1Name;
extern string Player2Name;
void SetShipType(int& iCurrentShip, int& iShipBeingPlaced, string& sShipName, char& cShipChar, char** EnemyGrid) // Cycles through all ships
{
	// Constants holding lengths of different ships
	const int ikSubmarine = 1;
	const int ikDestroyer = 2;
	const int ikCruiser = 3;
	const int ikBattleship = 4;
	const int ikAirCraftCarrier = 5;

	switch (iCurrentShip)
	{
	case 1: // Sub
		iShipBeingPlaced = ikSubmarine;
		sShipName = " 1 ";
		cShipChar = '1';

		break;

	case 2: // Destroyer
		iShipBeingPlaced = ikDestroyer;
		sShipName = "2";
		cShipChar = '2';

		break;

	case 3: // Cruiser
		iShipBeingPlaced = ikCruiser;
		sShipName = "3";
		cShipChar = '3';

		break;

	case 4: // BattleShip
		iShipBeingPlaced = ikBattleship;
		sShipName = "4";
		cShipChar = '4';

		break;

	case 5: // Air Craft Carrier
		iShipBeingPlaced = ikAirCraftCarrier;
		sShipName = "5";
		cShipChar = '5';

		break;

	default: // Runs correct default depending on if players are human or AI

		system("CLS");
		if (CurrentPlayer == 1)
		{
			if (GameMode == 2)
			{
				cout << "Ships placed. Pass the game to " << Player2Name << " so they may place ships." << endl;
				system("PAUSE");
				system("CLS");
				CurrentPlayer = 2;
				drawBoard(EnemyGrid);
			}

			iCurrentShip = 1;
			break;
		}

		if (CurrentPlayer == 2)
		{
			cout << Player2Name << " has finished placing his ships." << endl;
			cout << Player1Name << " will take the first shot" << endl;
			system("PAUSE");
			CurrentPlayer = 2;
			return;
		}
		break;
	}
}
