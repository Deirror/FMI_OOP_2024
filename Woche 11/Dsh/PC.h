#pragma once
#include "Computer.h"
class PC : public Computer
{
public:
	PC() = delete;
	PC(const char* videoCardModel, double cpuPower, size_t powerSupply, size_t ramCapacity);

	void printType() const override;
	void printPeripheralDevices() const override;
};

