#include "GamingConsole.h"
#include <iostream>

GamingConsole::GamingConsole(const char* videoCardModel, double cpuPower, size_t powerSupply, size_t ramCapacity) :
	Computer(videoCardModel, cpuPower, powerSupply, ramCapacity)
{
}

void GamingConsole::printType() const
{
	std::cout << "> Console\n";
}

void GamingConsole::printPeripheralDevices() const
{
	std::cout << "> Joystick, Monitor\n";
}
