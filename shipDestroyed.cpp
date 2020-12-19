#include"shipDestroyed.h"
#include<iostream>
using namespace std;
extern int CurrentPlayer;
extern int P1ShipHealth[5];
extern int P2ShipHealth[5];
void shipDestroyed(char HitChar)
{
		if (CurrentPlayer == 1) // If player 1's ships are hit.
	{
		switch (HitChar)
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
		switch (HitChar)
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
}