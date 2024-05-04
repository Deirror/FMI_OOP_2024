#include <iostream>
#include "StringVector.h"

int main()
{
	StringVector sv;

	String string = "Hajde bre";

	sv.push_back(std::move(string));
	sv.push_back("ASfd1");
	sv.push_back("ASfds2");

	sv.debug();

	return 0;
}


