#include"PlaceShips.h"
#include"drawBoard.h"
#include"SetShipType.h"
#include<fstream>
#include<string>
#include<iostream>
using namespace std;
extern const int GridSize;
extern int CurrentPlayer;
extern int GameMode;
void PlaceShips(char** PlayerGrid, char** EnemyGrid, fstream& File)
{
	string sShipName = "Submarine"; // Holds name for current ship

	int iCurrentShip = 1; // Holds the current selected ship amd changes to player can place all ships

	int iShipBeingPlaced = 1; // Stores the current ship being places and increments by 1 when a ship is placed.
	int iBlankCheck = 0; // Checks all spaces are empty before placing ship
	//char cY; // Character value for grid

	int iX=1; // X grid value
	int iY=1; // Y grid value

	char cShipChar = ' '; // Holds the character which represents the ship in the grid
	int iWhichDir; // Holds the direction the player wants to place a ship

	int iDirection = 1; // Allows the user to pick ship rotation
	bool bPlacingShips = true; // While the player is placing ships
	bool input = true;
	while (bPlacingShips) // While the player is placing ships
	{
		{
			if (CurrentPlayer == 1) // Let player 1 cycle through ships
			{
				SetShipType(iCurrentShip, iShipBeingPlaced, sShipName, cShipChar, EnemyGrid);
			}
			SetShipType(iCurrentShip, iShipBeingPlaced, sShipName, cShipChar, EnemyGrid);


			if (iCurrentShip > 5)
			{
				return; // Returns when all 5 ships have been placed.
			}
			//Take input
			do {
				cout << "Please select the X,Y coordinates for your " << sShipName << " : " << endl;
				cout << "X: ";

				cin >> iX;
				cout << endl;
				cout << "Y: ";
				cin >> iY; // Enter character X value
				cout << endl;
				if (iX - 1 <= 9 && iX - 1 >= 0 && iY - 1 <= 9 && iY - 1 >= 0)
				{
					break;
				}
			} while (input == true);
			{
				if (CurrentPlayer == 1)
				{
					if (PlayerGrid[iY - 1][iX - 1] == ' ') // and grid is location is empty
					{
						do {
							system("CLS");
							PlayerGrid[iY - 1][iX - 1] = cShipChar; // Places character to represent ship
							drawBoard(PlayerGrid);
							cout << "Which direction would you like it to face?" << endl;
							cout << "1.) UP" << endl << "2.) DOWN" << endl << "3.) RIGHT" << endl << "4.) LEFT" << endl;
							cin >> iWhichDir; // Asks for direction to be entered
							iBlankCheck = 1;
						} while (iWhichDir > 4 || iWhichDir < 1);
						switch (iWhichDir)
						{
						case 1: // Places ship upwards
							for (int j = 0; j < iShipBeingPlaced; j++) // For the length of the ship...
							{
								if (iY - 1 >= 0 && iY - 1 < GridSize && iX - 1 >= 0 && iX - 1 < GridSize && PlayerGrid[iY - 1][iX - 1] == ' ') // if the ship is within the grid and not intercepting another ship
								{
									iBlankCheck++; // Increment blank check...
								}
								iY -= 1; // Check next space
							}
							if (iBlankCheck == iShipBeingPlaced) // If all the spaces the ship needs are valid...
							{
								iY += iShipBeingPlaced; // Return iY to starting value
								for (int j = 0; j < iShipBeingPlaced; j++) // For the length of the current ship...
								{

									PlayerGrid[iY - 1][iX - 1] = cShipChar; // Place the ships character is spaces
									iY -= 1;
								}

							}

							else // If invalid location selected...
							{
								system("CLS");
								cout << "Invalid Location." << endl;
								iY += iShipBeingPlaced; // Return iY to the starting place
								PlayerGrid[iY - 1][iX - 1] = ' '; // Empty it
								drawBoard(PlayerGrid);
								iCurrentShip--; // Return ship to last ship.
								system("PAUSE");
							}


							break;

						case 2: // Places ship downwards
							for (int j = 0; j < iShipBeingPlaced; j++)
							{
								if (iY - 1 >= 0 && iY - 1 < GridSize && iX - 1 >= 0 && iX - 1 <= GridSize)
								{
									if (PlayerGrid[iY - 1][iX - 1] == ' ')
									{
										iBlankCheck++;
									}
								}
								iY += 1;
							}
							if (iBlankCheck == iShipBeingPlaced)
							{
								iY -= iShipBeingPlaced;
								for (int j = 0; j < iShipBeingPlaced; j++)
								{

									PlayerGrid[iY - 1][iX - 1] = cShipChar;
									iY += 1;
								}

							}

							else
							{
								system("CLS");
								cout << "Invalid Location." << endl;
								iY -= iShipBeingPlaced;
								PlayerGrid[iY - 1][iX - 1] = ' ';
								drawBoard(PlayerGrid);
								iCurrentShip--;
								system("PAUSE");
							}

							break;
						case 3: // Places ship facing toward the right
							for (int j = 0; j < iShipBeingPlaced; j++)
							{
								if (iY - 1 >= 0 && iY - 1 < GridSize && iX - 1 >= 0 && iX - 1 < GridSize && PlayerGrid[iY - 1][iX - 1] == ' ')
								{
									iBlankCheck++;
								}
								iX += 1;
							}
							if (iBlankCheck == iShipBeingPlaced)
							{
								iX -= iShipBeingPlaced;
								for (int j = 0; j < iShipBeingPlaced; j++)
								{

									PlayerGrid[iY - 1][iX - 1] = cShipChar;
									iX += 1;
								}

							}

							else
							{
								system("CLS");
								cout << "Invalid Location." << endl;
								iX -= iShipBeingPlaced;
								PlayerGrid[iY - 1][iX - 1] = ' ';
								drawBoard(PlayerGrid);
								iCurrentShip--;
								system("PAUSE");
							}

							break;

						case 4: // Places ship facing toward the left
							for (int j = 0; j < iShipBeingPlaced; j++)
							{
								if (iY - 1 >= 0 && iY - 1 < GridSize && iX - 1 >= 0 && iX - 1 < GridSize && PlayerGrid[iY - 1][iX - 1] == ' ')
								{
									iBlankCheck++;
								}
								iX -= 1;
							}
							if (iBlankCheck == iShipBeingPlaced)
							{
								iX += iShipBeingPlaced;
								for (int j = 0; j < iShipBeingPlaced; j++)
								{

									PlayerGrid[iY - 1][iX - 1] = cShipChar;
									iX -= 1;
								}

							}

							else
							{
								system("CLS");
								cout << "Invalid Location." << endl;
								iX += iShipBeingPlaced;
								PlayerGrid[iY - 1][iX - 1] = ' ';
								drawBoard(PlayerGrid);
								iCurrentShip--;
								system("PAUSE");
							}

							break;

						default:
							break;

						}
						system("CLS");
						drawBoard(PlayerGrid);
						iCurrentShip++; // Increments value so next ship is placed.

					}

				}
				if (CurrentPlayer == 2 && GameMode == 2) // If human player 2 is playing
				{
					if (EnemyGrid[iY - 1][iX - 1] == ' ')
					{
						do{
							system("CLS");
							EnemyGrid[iY - 1][iX - 1] = cShipChar; // Places character to represent ship
							drawBoard(EnemyGrid);
							cout << "Which direction would you like it to face?" << endl;
							cout << "1.) UP" << endl << "2.) DOWN" << endl << "3.) RIGHT" << endl << "4.) LEFT" << endl;
							cin >> iWhichDir;
							iBlankCheck = 1;
						} while (iWhichDir>4|| iWhichDir<1);
						switch (iWhichDir)
						{
						case 1: // Places ship upwards
							for (int j = 0; j < iShipBeingPlaced; j++) // For the length of the ship...
							{
								if (iY - 1 >= 0 && iY - 1 < GridSize && iX - 1 >= 0 && iX - 1 < GridSize && EnemyGrid[iY - 1][iX - 1] == ' ') // if the ship is within the grid and not intercepting another ship
								{
									iBlankCheck++; // Increment blank check...
								}
								iY -= 1; // Check next space
							}
							if (iBlankCheck == iShipBeingPlaced) // If all the spaces the ship needs are valid...
							{
								iY += iShipBeingPlaced; // Return iY to starting value
								for (int j = 0; j < iShipBeingPlaced; j++) // For the length of the current ship...
								{

									EnemyGrid[iY - 1][iX - 1] = cShipChar; // Place the ships character is spaces
									iY -= 1;
								}

							}

							else // If invalid location selected...
							{
								system("CLS");
								cout << "Invalid Location." << endl;
								iY += iShipBeingPlaced; // Return iY to the starting place
								EnemyGrid[iY - 1][iX - 1] = ' '; // Empty it
								drawBoard(EnemyGrid);
								iCurrentShip--; // Return ship to last ship.
								system("PAUSE");
							}


							break;

						case 2: // Places ship downwards
							for (int j = 0; j < iShipBeingPlaced; j++)
							{
								if (iY - 1 >= 0 && iY - 1 < GridSize && iX - 1 >= 0 && iX - 1 < GridSize && EnemyGrid[iY - 1][iX - 1] == ' ')
								{
									iBlankCheck++;
								}
								iY += 1;
							}
							if (iBlankCheck == iShipBeingPlaced)
							{
								iY -= iShipBeingPlaced;
								for (int j = 0; j < iShipBeingPlaced; j++)
								{

									EnemyGrid[iY - 1][iX - 1] = cShipChar;
									iY += 1;
								}

							}

							else
							{
								system("CLS");
								cout << "Invalid Location." << endl;
								iY -= iShipBeingPlaced;
								EnemyGrid[iY - 1][iX - 1] = ' ';
								drawBoard(EnemyGrid);
								iCurrentShip--;
								system("PAUSE");
							}

							break;

						case 3: // Places ship facing toward the right
							for (int j = 0; j < iShipBeingPlaced; j++)
							{
								if (iY - 1 >= 0 && iY - 1 < GridSize && iX - 1 >= 0 && iX - 1 < GridSize && EnemyGrid[iY - 1][iX - 1] == ' ')
								{
									iBlankCheck++;
								}
								iX += 1;
							}
							if (iBlankCheck == iShipBeingPlaced)
							{
								iX -= iShipBeingPlaced;
								for (int j = 0; j < iShipBeingPlaced; j++)
								{

									EnemyGrid[iY - 1][iX - 1] = cShipChar;
									iX += 1;
								}

							}

							else
							{
								system("CLS");
								cout << "Invalid Location." << endl;
								iX -= iShipBeingPlaced;
								EnemyGrid[iY - 1][iX - 1] = ' ';
								drawBoard(EnemyGrid);
								iCurrentShip--;
								system("PAUSE");
							}

							break;


						case 4: // Places ship facing toward the left
							for (int j = 0; j < iShipBeingPlaced; j++)
							{
								if (iY - 1 >= 0 && iY - 1 < GridSize && iX - 1 >= 0 && iX - 1 < GridSize && EnemyGrid[iY - 1][iX - 1] == ' ')
								{
									iBlankCheck++;
								}
								iX -= 1;
							}
							if (iBlankCheck == iShipBeingPlaced)
							{
								iX += iShipBeingPlaced;
								for (int j = 0; j < iShipBeingPlaced; j++)
								{

									EnemyGrid[iY - 1][iX - 1] = cShipChar;
									iX -= 1;
								}

							}

							else
							{
								system("CLS");
								cout << "Invalid Location." << endl;
								iX += iShipBeingPlaced;
								EnemyGrid[iY - 1][iX - 1] = ' ';
								drawBoard(EnemyGrid);
								iCurrentShip--;
								system("PAUSE");
							}

							break;

						default:
							break;

						}
						system("CLS");
						drawBoard(EnemyGrid);
						iCurrentShip++;
					}
				}
			}

		}
	}
}