#include"switchCurrentPlayer.h"
extern int CurrentPlayer ;
int switchCurrentPlayer() // Switches the current player
{
	if (CurrentPlayer == 1)
	{
		CurrentPlayer = 2;
	}

	else if (CurrentPlayer == 2)
	{
		CurrentPlayer = 1;
	}

	return CurrentPlayer;
}