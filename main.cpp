#include <string>
#include <iostream>
#include<fstream>
#include "clearBoard.h"
#include"drawBoard.h"
#include"writeContents.h"
#include"mainMenu.h"
#include"playGame.h"
#include"PlaceShips.h"
#include"openFileIn.h"
#include"showContents.h"
//#include"playerShooting.h"
//#include"CheckResult.h"
//#include"switchCurrentPlayer.h"
using namespace std;

const int GridSize = 10; // A constant holding size of all arrays
int rocket1 = 16;
int score1 = 0;
int score2 = 0;
int rocket2 = 16;
int CurrentPlayer = 1;
string Player1Name; // Holds player 1's name 
string Player2Name; // Holds player 2's name

int GameMode; // Holds data on if the player is playing a human or AI opponent
int P1ShipHealth[5] = { 1,2,3,4,5 }; // Holds the ship health for the sub,cruiser,destroyer,battleship and air craft carrier

int P2ShipHealth[5] = { 1,2,3,4,5 }; // Holds the ship health for the sub,cruiser,destroyer,battleship and air craft carrier for player 2

//void clearBoard(char** acArray); // Clears the board
//void drawBoard(char** acWhichBoard); // Draws a board and places a given array inside of it.
//void writeContents(fstream&, int, char**, char*);
//void PlaceShips(char**, char**, fstream &); // Places the ships
//void playerShooting(char**, char**, char**, bool*); // Allows the players to shoot at eachothers ships
//void playGame(char**, char**, char**, char**); // Overall game loop
//int switchCurrentPlayer(); // Switches the current player to the other player
//int mainMenu(); // Draws the main menu
//void shipDestroyed(char cHitChar, bool* GameEnd); // If a ship is hit this function counts which ship was hit and if it has been destroyed.
//void SetShipType(int& iCurrentShip, int& iShipBeingPlaced, string& sShipName, char& cShipChar, char** EnemyGrid); // 'For' statment which cycles through my games ships for placement.
//void CheckResult(bool*);
int main()
{
	char run[2][12] = { { 'p','l','a','y','e','r','1','.','t','x','t' } ,{'p','l','a','y','e','r','2','.','t','x','t'} };
	char** PlayerGrid = new char* [GridSize]; // Holds player ship locations
	fstream dataFile;
	for (int i = 0; i < GridSize; i++)
	{
		PlayerGrid[i] = new char[GridSize];
	}
	for (int i = 0; i < GridSize; i++)
	{
		for (int j = 0; j < GridSize; j++)
		{
			PlayerGrid[i][j] = NULL;
		}
	}

	char** PlayerHits = new char* [GridSize]; // Holds players hit locations
	for (int i = 0; i < GridSize; i++) {

		PlayerHits[i] = new char[GridSize];
	}
	for (int i = 0; i < GridSize; i++)
	{
		for (int j = 0; j < GridSize; j++)
		{
			PlayerHits[i][j] = NULL;
		}
	}
	char** EnemyGrid = new char* [GridSize]; // Holds Enemy ship locations
	for (int i = 0; i < GridSize; i++)
	{
		EnemyGrid[i] = new char[GridSize];
	}
	for (int i = 0; i < GridSize; i++)
	{
		for (int j = 0; j < GridSize; j++)
		{
			EnemyGrid[i][j] = NULL;
		}
	}
	char** EnemyHits = new char* [GridSize]; // Holds Enemy hit locations
	for (int i = 0; i < GridSize; i++)
	{
		EnemyHits[i] = new char[GridSize];
	}
	for (int i = 0; i < GridSize; i++)
	{
		for (int j = 0; j < GridSize; j++)
		{
			EnemyHits[i][j] = NULL;
		}
	}

	int iChoice; // clears iChoice

	iChoice = mainMenu(); //Receives result from MainMenu function

	if (iChoice == 3) // If player selected exit...
	{
		return 0; // End program
	}

	else
	{
		// Otherwise clear both grids
		clearBoard(PlayerGrid);
		clearBoard(EnemyGrid);
		int i = 0;
		while (i < 2)
		{
			//clearBoard(Board, Grid_Size);
			writeContents(dataFile, GridSize, PlayerGrid, run[i]);
			i++;
		}
		int n = 0;
		while (n < 2)
		{
			if (!openFileIn(dataFile, run[n]))
			{
				cout << "File open error" << endl;
				return 0;	//Exit program on error.
			}
			else
			{
				//cout << "Opening file "<<n+1<<endl;
				//cout << "Now writing data to the file " << n + 1 << endl;
				showContents(dataFile);
				dataFile.close();
				//cout << "File " << n + 1 << " :  Done \n";
				cout << endl;
				n++;
			}
		}
		system("PAUSE");
	}
	if (iChoice == 2)
	{
		GameMode = 2; // Multiplayer
		system("CLS");
		cout << Player1Name << " will place his ships first." << endl;
		system("PAUSE");
		system("CLS");
		drawBoard(PlayerGrid); // Draws both grids
		PlaceShips(PlayerGrid, EnemyGrid, dataFile); // Players place ships
		int i = 0;
			//clearBoard(Board, Grid_Size);
			writeContents(dataFile, GridSize, PlayerGrid, run[i]);
			writeContents(dataFile, GridSize, EnemyGrid, run[i + 1]);
		playGame(PlayerGrid, EnemyHits, EnemyGrid, PlayerHits);
		return 0;
	}
	for (int i = 0; i < GridSize; i++)
	{
		delete[] PlayerGrid[i];
	}

	delete[] PlayerGrid;
	for (int i = 0; i < GridSize; i++)
	{
		delete[] PlayerHits[i];
	}

	delete[] PlayerHits;
	for (int i = 0; i < GridSize; i++)
	{
		delete[]EnemyGrid[i];
	}

	delete[] EnemyGrid;
	for (int i = 0; i < GridSize; i++)
	{
		delete[]EnemyHits[i];
	}
	delete[] EnemyHits;
	system("PAUSE");
	return 0;
}


/*void shipDestroyed(char cHitsChar, bool* GameEnd)
{
	if (P1ShipHealth[0] == 0 && P1ShipHealth[1] == 0 && P1ShipHealth[2] == 0 && P1ShipHealth[3] == 0 && P1ShipHealth[4] == 0) // All a player 1's ships have been destroyed.
	{
		int a, b, c, d, e;
		a = P1ShipHealth[0];
		b = P1ShipHealth[1];
		c = P1ShipHealth[2];
		d = P1ShipHealth[3];
		e = P1ShipHealth[4];
		system("CLS");
		cout << Player1Name << " Wins." << endl;
		//exit(EXIT_SUCCESS);
		system("PAUSE");
		*GameEnd = CheckGameEnd(&a, &b, &c, &d, &e);
		//break;
	}

	if (P2ShipHealth[0] == 0 && P2ShipHealth[1] == 0 && P2ShipHealth[2] == 0 && P2ShipHealth[3] == 0 && P2ShipHealth[4] == 0) // All player 2's ships have been destroyed.
	{
		int a, b, c, d, e;
		a = P2ShipHealth[0];
		b = P2ShipHealth[1];
		c = P2ShipHealth[2];
		d = P2ShipHealth[3];
		e = P2ShipHealth[4];
		system("CLS");
		cout << Player2Name << " Wins." << endl;
		//exit(EXIT_SUCCESS);
		system("PAUSE");
		*GameEnd = CheckGameEnd(&a, &b, &c, &d, &e);
		//break;
	}
	if (CurrentPlayer == 1) // If player 1's ships are hit.
	{
		switch (cHitsChar)
		{
		case '1': // If sub hit
			P1ShipHealth[0]--; // Decrease Sub health
			if (P1ShipHealth[0] == 0) // If health is 0
			{
				cout << endl << "1 has been sunk." << endl; // Show sunk message
				system("PAUSE");
			}

			break;

		case '2': // Destroyer
			P1ShipHealth[1]--;
			if (P1ShipHealth[1] == 0)
			{
				cout << endl << "2 has been sunk." << endl;
				system("PAUSE");
			}

			break;

		case '3': // Cruiser
			P1ShipHealth[2]--;
			if (P1ShipHealth[2] == 0)
			{
				cout << endl << "3 has been sunk." << endl;
				system("PAUSE");
			}

			break;

		case '4': // Battleship
			P1ShipHealth[3]--;
			if (P1ShipHealth[3] == 0)
			{
				cout << endl << "4 has been sunk." << endl;
				system("PAUSE");
			}

			break;

		case '5': // Aircraft carrier
			P1ShipHealth[4]--;
			if (P1ShipHealth[4] == 0)
			{
				cout << endl << "5 has been sunk." << endl;
				system("PAUSE");
			}

			break;
		}
	}

	else if (CurrentPlayer == 2) // Same as above for player 2
	{
		switch (cHitsChar)
		{
		case '1':
			P2ShipHealth[0]--;
			if (P2ShipHealth[0] == 0)
			{
				cout << endl << "1 has been sunk." << endl;
				system("PAUSE");
			}
			break;

		case '2':
			P2ShipHealth[1]--;
			if (P2ShipHealth[1] == 0)
			{
				cout << endl << "2 has been sunk." << endl;
				system("PAUSE");
			}
			break;

		case '3':
			P2ShipHealth[2]--;
			if (P2ShipHealth[2] == 0)
			{
				cout << endl << "3 has been sunk." << endl;
				system("PAUSE");
			}

			break;

		case '4':
			P2ShipHealth[3]--;
			if (P2ShipHealth[3] == 0)
			{
				cout << endl << "4 has been sunk." << endl;
				system("PAUSE");
			}

			break;

		case '5':
			P2ShipHealth[4]--;
			if (P2ShipHealth[4] == 0)
			{
				cout << endl << "5 has been sunk." << endl;
				system("PAUSE");
			}

			break;
		}
	}
}*/
/*bool openFileIn(fstream& file, char* name)
{
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;
}*/
/*
void showContents(fstream& file)
{
	string str;
	//file.getline(file, str);
	while (getline(file, str))
	{
		cout << str << "\n";
	}
}*/


