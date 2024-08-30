#include <iostream>
#include "StringVector.h"

int main()
{
	StringVector sv;

	sv.push_back("All");
	sv.push_back("Alls");
	sv.push_back("Allz");

	sv.insert("As", 0);

	sv.push_back("Allzsz679");
	sv.push_back("Allzsz6791");
	sv.push_back("Allzsz672");
	sv.push_back("Allzsz6723");
	sv.push_back("Allzsz6723ds");

	sv.erase(0);
	sv.erase(0);

	sv.debug();

	return 0;
}