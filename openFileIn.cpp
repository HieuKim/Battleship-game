#include"openFileIn.h"
#include<fstream>
using namespace std;
bool openFileIn(fstream& file, char* name)
{
	file.open(name, ios::in);
	if (file.fail())
		return false;
	else
		return true;
}