#include"clearBoard.h"
extern const int GridSize;
void clearBoard(char** acArray)
{
	for (int iY = 0; iY < GridSize; iY++) // Go though all values...
	{
		for (int iX = 0; iX < GridSize; iX++)
		{
			acArray[iX][iY] = ' '; // And reset them to empty
		}
	}
}
