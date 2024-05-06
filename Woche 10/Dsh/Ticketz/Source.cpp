#include <iostream>
#include "GroupTicket.h"
#include "StudentTicket.h"


int main()
{
	String string = "Idar";

	StudentTicket st(string, 20.0);

	st.printTicket();

	string += "an";

	GroupTicket gt(string, 50.0);

	gt.printTicket();

	return 0;
}