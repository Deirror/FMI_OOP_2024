#include "Computer.h"
#include <utility>
#include <cstring>
#include <exception>
#pragma warning(disable : 4996)

Computer::Computer(const char* videoCardModel, double cpuPower, size_t powerSupply, size_t ramCapacity)
{
	setCpuPower(cpuPower);
	setPowerSupply(powerSupply);
	setRamCapacity(ramCapacity);
	setVideoCardModel(videoCardModel);
}

Computer::Computer(const Computer& other)
{
	copyFrom(other);
}

Computer& Computer::operator=(const Computer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Computer::Computer(Computer&& other) noexcept
{
	moveFrom(std::move(other));
}

Computer& Computer::operator=(Computer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

Computer::~Computer()
{
	delete[] _videoCardModel;
}

void Computer::setCpuPower(double cpuPower)
{
	if (cpuPower < 0.)
		throw std::exception("Negative number");

	_cpuPower = cpuPower;
}

void Computer::setVideoCardModel(const char* videoCardModel)
{
	if (!videoCardModel)
		throw std::exception("Nullptr");

	delete[] _videoCardModel;
	_videoCardModel = new char[strlen(videoCardModel) + 1] {};

	strcpy(_videoCardModel, videoCardModel);
}

void Computer::setPowerSupply(size_t poweSupply)
{
	_powerSupply = poweSupply;
}

void Computer::setRamCapacity(size_t ramCapacity)
{
	_ramCapacity = ramCapacity;
}

void Computer::free()
{
	delete[] _videoCardModel;
	_videoCardModel = nullptr;
	_ramCapacity = _powerSupply = 0;
	_cpuPower = 0.;
}

void Computer::copyFrom(const Computer& other)
{
	_cpuPower = other._cpuPower;
	_ramCapacity = other._ramCapacity;
	_powerSupply = other._powerSupply;

	_videoCardModel = new char[strlen(other._videoCardModel) + 1] {};

	strcpy(_videoCardModel, other._videoCardModel);
}

void Computer::moveFrom(Computer&& other)
{
	_cpuPower = other._cpuPower;
	_ramCapacity = other._ramCapacity;
	_powerSupply = other._powerSupply;

	other._cpuPower = other._powerSupply = other._ramCapacity = 0;

	_videoCardModel = other._videoCardModel;

	other._videoCardModel = nullptr;
}
