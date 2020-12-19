#include"playerShooting.h"
#include<iostream>
#include"drawBoard.h"
using namespace std;
extern string Player1Name;
extern string Player2Name;
extern const int GridSize ; // A constant holding size of all arrays
extern int rocket1 ;
extern int score1 ;
extern int score2 ;
extern int rocket2 ;
extern int GameMode; // Holds data on if the player is playing a human 
extern int P1ShipHealth[5];
extern int CurrentPlayer;
extern int P2ShipHealth[5];
void playerShooting(char** acBoard, char** acHits, char** acDmgBoard, bool* GameEnd)
{
	char cHitChar = ' '; // Character that is hit
	//char cY; // Shot value
	int ShootX;
	int ShootY;
	//bool bHit = true; // While the last shot was a hit
	//bool game_end = *GameEnd;
	system("CLS");
	if (CurrentPlayer == 1 || CurrentPlayer == 2
		&& GameMode == 2) // If its player 1 or a human player 2
	{
		drawBoard(acBoard);
		drawBoard(acHits);
	}
	if (GameMode == 2 || CurrentPlayer == 1) // If its player 1 and single player
	{
		do
		{
			cout << "Where would you like to shoot? (X,Y)" << endl;
			cout << "X: ";
			cin >> ShootX;
			cout << endl;
			while (ShootX > 10 || ShootX < 1) // Invalid location entered
			{
				cout << "That position is invalid. Please try again" << endl;
				//system("CLS");
				cout << "X: ";
				cin >> ShootX;
				cout << endl;
			}
			cout << "Y: ";
			cin >> ShootY; // Enter character X value

			//ShootY = toupper(cY); // Convert to upper value			
			//ShootY -= 64;

			while (ShootY > 10 || ShootY < 1) // Invalid location entered
			{
				cout << "That position is invalid. Please try again" << endl;
				//system("CLS");
				cout << "Y: ";
				cin >> ShootY; // Enter character X value

				//ShootY = toupper(cY); // Convert to upper value			
				//ShootY -= 64;
			}
		} while (acHits[ShootY - 1][ShootX - 1] == 'X' || acHits[ShootY - 1][ShootX - 1] == 'M');
	}

	if (
		acHits[ShootY - 1][ShootX - 1] != 'X' && acHits[ShootY - 1][ShootX - 1] != 'M') // If player have not already shot this place before
	{
		if (acDmgBoard[ShootY - 1][ShootX - 1] != ' ') // Player hits then...
		{
			cHitChar = acDmgBoard[ShootY - 1][ShootX - 1]; // Find out which ship has been hit
			acHits[ShootY - 1][ShootX - 1] = 'X'; // Mark hit with an 'X'
			acDmgBoard[ShootY - 1][ShootX - 1] = 'X'; // Mark hit players ship with an 'X'
			system("CLS");
			if (CurrentPlayer == 1 || CurrentPlayer == 2 && GameMode == 2)
			{
				drawBoard(acBoard);
			}
			drawBoard(acHits);
			//shipDestroyed(cHitChar); 
			if (CurrentPlayer == 1) // If player 1's ships are hit.
			{
				switch (cHitChar)
				{
				case '1': // If sub hit
					P1ShipHealth[0]--; // Decrease Sub health
					score1 += 1;
					if (P1ShipHealth[0] == 0) // If health is 0
					{
						cout << endl << "1 has been sunk." << endl; // Show sunk message
						system("PAUSE");
					}

					break;

				case '2': // Destroyer
					P1ShipHealth[1]--;
					score1 += 2;
					if (P1ShipHealth[1] == 0)
					{
						cout << endl << "2 has been sunk." << endl;
						system("PAUSE");
					}

					break;

				case '3': // Cruiser
					P1ShipHealth[2]--;
					score1 += 3;
					if (P1ShipHealth[2] == 0)
					{
						cout << endl << "3 has been sunk." << endl;
						system("PAUSE");
					}

					break;

				case '4': // Battleship
					P1ShipHealth[3]--;
					score1 += 4;
					if (P1ShipHealth[3] == 0)
					{
						cout << endl << "4 has been sunk." << endl;
						system("PAUSE");
					}

					break;

				case '5': // Aircraft carrier
					P1ShipHealth[4]--;
					score1 += 5;
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
				switch (cHitChar)
				{
				case '1':
					P2ShipHealth[0]--;
					score2 += 1;
					if (P2ShipHealth[0] == 0)
					{
						cout << endl << "1 has been sunk." << endl;
						system("PAUSE");
					}
					break;

				case '2':
					P2ShipHealth[1]--;
					score2 += 2;
					if (P2ShipHealth[1] == 0)
					{
						cout << endl << "2 has been sunk." << endl;
						system("PAUSE");
					}
					break;

				case '3':
					P2ShipHealth[2]--;
					score2 += 3;
					if (P2ShipHealth[2] == 0)
					{
						cout << endl << "3 has been sunk." << endl;
						system("PAUSE");
					}

					break;

				case '4':
					P2ShipHealth[3]--;
					score2 += 4;
					if (P2ShipHealth[3] == 0)
					{
						cout << endl << "4 has been sunk." << endl;
						system("PAUSE");
					}

					break;

				case '5':
					P2ShipHealth[4]--;
					score2 += 5;
					if (P2ShipHealth[4] == 0)
					{
						cout << endl << "5 has been sunk." << endl;
						system("PAUSE");
					}

					break;
				}
			}
			cout << "HIT!!" << endl;
			cout << Player1Name << "'s score: " << score1 << endl;
			cout << Player2Name << "'s score: " << score2 << endl;
			system("PAUSE");
		}
		else
		{
			system("CLS"); // If player misses
			acHits[ShootY - 1][ShootX - 1] = 'M'; // Mark miss location with an 'M'
			if (CurrentPlayer == 1 || CurrentPlayer == 2 && GameMode == 2) // If against human player
			{
				drawBoard(acBoard);
			}
			drawBoard(acHits);
			if (CurrentPlayer == 1) // Player 1 missed
			{
				cout << endl << Player1Name << " missed" << endl;
				cout << Player1Name << "'s score: " << score1 << endl;
			}
			else if (CurrentPlayer == 2) // Player 2 missed
			{
				cout << endl << Player2Name << " missed" << endl;
				cout << Player2Name << "'s score: " << score2 << endl;
			}
			system("PAUSE");
			system("CLS");
		}
	}
}