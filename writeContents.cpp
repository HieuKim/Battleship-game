#include"writeContents.h"
#include<fstream>
using namespace std;
void writeContents(fstream& File, int GridSize, char** ac, char* arr)
{
	File.open(arr, ios::out);
	if (File.fail())
	{
		File.open(arr, ios::out);
	}
	else
	{
		//cout << "Now writing data player 1 to the file " << endl;
		File << "10\n";
		File << "   "; // Inital spacing
		//dataFile << "  "; // Inital spacing  
		//dataFile << " "; // Add 1 space in here
		for (int iX = 0; iX < GridSize; iX++)
		{
			File << " " << iX + 1 << "  "; // Top Numbers
		}
		File << endl;
		File << " ";
		File << " "; // Add 1 space in here
		for (int iX = 0; iX < 10; iX++)
		{
			File << "+---"; // Top line
		}
		File << "+" << endl; // Final plus
		for (int iY = 0; iY < 10; iY++)
		{
			if (iY + 1 < 10)
			{
				File << iY + 1 << " "; // Displays side numbers
			}
			else
			{
				File << iY + 1;
			}
			for (int iX = 0; iX < 10; iX++)
			{
				File << "| " << ac[iY][iX] << " "; // Places array inside grid
			}
			File << "|" << endl;
			File << "  ";
			for (int iX = 0; iX < 10; iX++)
			{
				File << "+---"; // Draws last lines
			}
			File << "+" << endl; // Final plus
		}
		File << endl;


		File.close();

		//	cout << "Done" << endl;
	}
}