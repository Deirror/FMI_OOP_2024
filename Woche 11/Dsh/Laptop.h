#pragma once
#include "Computer.h"
class Laptop : public Computer
{
public:
	Laptop() = delete;
	Laptop(const char* videoCardModel, double cpuPower, size_t powerSupply, size_t ramCapacity);

	void printType() const override;
	void printPeripheralDevices() const override;
};

