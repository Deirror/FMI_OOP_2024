#include <iostream>
#include "StringVector.h"

int main()
{
	StringVector sv;

	sv.push_back("All");
	sv.push_back("Alls");
	sv.push_back("Allz");

	std::cout << sv[2];

	sv.insert("As", 0);

	sv.erase(1);

	return 0;
}