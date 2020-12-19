#include"showContents.h"
#include<fstream>
#include<iostream>
#include<string>
using namespace std;
void showContents(fstream& file)
{
	string str;
	//file.getline(file, str);
	while (getline(file, str))
	{
		cout << str << "\n";
	}
}