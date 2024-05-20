#include "PC.h"
#include <iostream>

PC::PC(const char* videoCardModel, double cpuPower, size_t powerSupply, size_t ramCapacity) :
	Computer(videoCardModel, cpuPower, powerSupply, ramCapacity)
{

}

void PC::printType() const
{
	std::cout << "> PC\n";
}

void PC::printPeripheralDevices() const
{
	std::cout << "> Mouse, Keyboard, Microphone, Headphones\n";
}


