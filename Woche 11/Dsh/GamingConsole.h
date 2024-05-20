#pragma once
#include "Computer.h"

class GamingConsole : public Computer
{
public:
	GamingConsole() = delete;
	GamingConsole(const char* videoCardModel, double cpuPower, size_t powerSupply, size_t ramCapacity);

	void printType() const override;
	void printPeripheralDevices() const override;
};

