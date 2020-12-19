#include"mainMenu.h"
#include<iostream>
#include<string>
using namespace std;
extern string Player1Name; // Holds player 1's name 
extern string Player2Name; // Holds player 2's name
int mainMenu()
{
	// Draws a main menu user interface
	int iMenuChoice;
	cout << "**************************************************" << endl;
	cout << "                    Battleships                   " << endl;
	cout << "**************************************************" << endl << endl;
	cout << "Welcome! You have total 16 rockets each person to shoot respectively." << endl;
	cout << "What would you like to play?" << endl << endl;

	//cout << "1.) Single Player" << endl;
	cout << "2.) Multiplayer" << endl;
	cout << "3.) Exit Game" << endl;

	cin >> iMenuChoice; // Asks for user's choice
	while (iMenuChoice > 3 || iMenuChoice <= 1)
	{
		system("CLS");
		cout << "**************************************************" << endl;
		cout << "                    Battleships                   " << endl;
		cout << "**************************************************" << endl << endl;
		cout << "Welcome! You have total 16 rockets each person to shoot respectively." << endl;
		cout << "What would you like to play?" << endl << endl;

		cout << "2.) Multiplayer" << endl;
		cout << "3.) Exit Game" << endl;
		//cout << "1.) Single Player" << endl;
		cin >> iMenuChoice;
	}
	if (iMenuChoice == 2) // If multiplayer selected then ask for both players names
	{
		cout << "Enter Player 1 Name: ";
		cin >> Player1Name;
		cout << "Enter Player 2 Name: ";
		cin >> Player2Name;
	}

	else   //if (iMenuChoice == 3) // If exit selected send message
	{
		cout << "Thanks for playing" << endl;
		system("PAUSE");
	}

	system("CLS");
	return iMenuChoice;
}