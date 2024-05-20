#include "Laptop.h"
#include <iostream>

Laptop::Laptop(const char* videoCardModel, double cpuPower, size_t powerSupply, size_t ramCapacity) :
	Computer(videoCardModel, cpuPower, powerSupply, ramCapacity)
{
}

void Laptop::printType() const
{
	std::cout << "> Laptop\n";
}

void Laptop::printPeripheralDevices() const
{
	std::cout << "> Mouse Pad, Keyboard, Monitor\n";
}