#include"playGame.h"
#include"switchCurrentPlayer.h"
#include"CheckResult.h"
#include"playerShooting.h"
#include<iostream>
#include<string>
using namespace std;
extern string Player1Name;
extern string Player2Name;
extern const int GridSize; // A constant holding size of all arrays
extern int rocket1 ;
extern int score1 ;
extern int score2 ;
extern int rocket2 ;
extern int CurrentPlayer;
void playGame(char** PlayerGrid, char** EnemyHits, char** EnemyGrid, char** PlayerHits)
{
	bool GameEnd = false;
	int rocket = 0;
	//bool TestGameEnd = false;
	/*||*/ /*(rocket1 <1 && rocket2<1)*/
	while (GameEnd == false) // While game has not ended
	{
		switchCurrentPlayer(); // Switch Player
		cout << CurrentPlayer << endl;
		if (CurrentPlayer == 1) // Run routine for coresponding player
		{
			system("CLS");
			cout << Player1Name << "'s turn" << endl;
			system("PAUSE");
			rocket1--;
			playerShooting(PlayerGrid, EnemyHits, EnemyGrid, &GameEnd);
		}
		if (CurrentPlayer == 2)
		{
			system("CLS");
			cout << Player2Name << "'s turn" << endl;
			system("PAUSE");
			rocket2--;
			playerShooting(EnemyGrid, PlayerHits, PlayerGrid, &GameEnd);
		}
		rocket++;
		CheckResult(&GameEnd);
	}
}