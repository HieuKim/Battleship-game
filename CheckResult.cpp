#include"CheckResult.h"
#include<string>
#include<iostream>
using namespace std;
extern const int GridSize ; // A constant holding size of all arrays
extern int rocket1 ;
extern int score1 ;
extern int score2 ;
extern int rocket2 ;
extern int CurrentPlayer ;
extern string Player1Name; // Holds player 1's name 
extern string Player2Name; // Holds player 2's name

extern int GameMode; // Holds data on if the player is playing a human 
extern int P1ShipHealth[5] ; 

extern int P2ShipHealth[5] ;
void CheckResult(bool* GameEnd)
{
	if ((rocket1 == 0) && (rocket2 == 0))
	{
		if (score1 > score2)
		{
			system("PAUSE");
			system("CLS");
			cout << Player1Name << " wins" << endl;
			cout << Player1Name << "'s score: " << score1 << endl;
			cout << Player2Name << "'s score: " << score2 << endl;
			*GameEnd = true;
		}
		if (score1 < score2)
		{
			system("PAUSE");
			system("CLS");
			cout << Player2Name << " wins" << endl;
			cout << Player1Name << "'s score: " << score1 << endl;
			cout << Player2Name << "'s score: " << score2 << endl;
			*GameEnd = true;
		}
		if (score1 == score2)
		{
			system("PAUSE");
			system("CLS");
			cout << "Drawn game " << endl;
			cout << Player1Name << "'s score: " << score1 << endl;
			cout << Player2Name << "'s score: " << score2 << endl;
			*GameEnd = true;
		}
	}
	if (rocket1 == 1 && rocket2 == 1)
	{
		if (P1ShipHealth[0] == 0 && P1ShipHealth[1] == 0 && P1ShipHealth[2] == 0 && P1ShipHealth[3] == 0 && P1ShipHealth[4] == 0 && P2ShipHealth[0] == 0 && P2ShipHealth[1] == 0 && P2ShipHealth[2] == 0 && P2ShipHealth[3] == 0 && P2ShipHealth[4] == 0)
		{
			system("PAUSE");
			system("CLS");
			cout << "Drawn game: " << endl;
			cout << Player1Name << "'s score: " << score1 << endl;
			cout << Player2Name << "'s score: " << score2 << endl;
			*GameEnd = true;
		}
		if (score1 == 55 && score1 > score2)
		{
			system("PAUSE");
			system("CLS");
			cout << Player1Name << " wins" << endl;
			cout << Player1Name << "'s score: " << score1 << endl;
			cout << Player2Name << "'s score: " << score2 << endl;
			*GameEnd = true;
		}
		if (score2 == 55 && score1 < score2)
		{
			system("PAUSE");
			system("CLS");
			cout << Player2Name << " wins" << endl;
			cout << Player1Name << "'s score: " << score1 << endl;
			cout << Player2Name << "'s score: " << score2 << endl;
			*GameEnd = true;
		}
	}
	//&& P1ShipHealth[0] == 0 && P1ShipHealth[1] == 0 && P1ShipHealth[2] == 0 && P1ShipHealth[3] == 0 && P1ShipHealth[4] == 0&& P2ShipHealth[0] == 0 && P2ShipHealth[1] == 0 && P2ShipHealth[2] == 0 && P2ShipHealth[3] == 0 && P2ShipHealth[4] == 0
}