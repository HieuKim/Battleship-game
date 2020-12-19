#include"drawBoard.h"
#include<iostream>
using namespace std;
extern const int GridSize;
void drawBoard(char** WhichBoard)
{
	cout << "10\n";
	cout << "   "; // Inital spacing
		//dataFile << "  "; // Inital spacing  
		//dataFile << " "; // Add 1 space in here
	for (int iX = 0; iX < GridSize; iX++)
	{
		cout << " " << iX + 1 << "  "; // Top Numbers
	}
	cout << endl;
	cout << " ";
	cout << " "; // Add 1 space in here
	for (int iX = 0; iX < 10; iX++)
	{
		cout << "+---"; // Top line
	}
	cout << "+" << endl; // Final plus
	for (int iY = 0; iY < 10; iY++)
	{
		if (iY + 1 < 10)
		{
			cout << iY + 1 << " "; // Displays side numbers
		}
		else
		{
			cout << iY + 1;
		}
		for (int iX = 0; iX < 10; iX++)
		{
			cout << "| " << WhichBoard[iY][iX] << " "; // Places array inside grid
		}
		cout << "|" << endl;
		cout << "  ";
		for (int iX = 0; iX < 10; iX++)
		{
			cout << "+---"; // Draws last lines
		}
		cout << "+" << endl; // Final plus
	}
	cout << endl;
}