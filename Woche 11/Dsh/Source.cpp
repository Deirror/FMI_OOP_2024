#include <iostream>
#include "GamingConsole.h"
#include "PC.h"
#include "Laptop.h"

int main()
{
	Computer** cmp = new Computer * [4];
		
	cmp[0] = new PC("Bruh", 1, 1, 1);
	cmp[1] = new Laptop("Yoga", 2, 2, 2);
	cmp[2] = new PC("MastarEmkata", 3, 3, 2);
	cmp[3] = new GamingConsole("Bahti", 12, 30, 20);


	cmp[0]->printType();
	cmp[0]->printPeripheralDevices();



	return 0;
}