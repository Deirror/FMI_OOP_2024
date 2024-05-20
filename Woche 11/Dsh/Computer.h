#pragma once

class Computer
{
protected:
	double _cpuPower = 0.;
	char* _videoCardModel = nullptr;

	size_t _powerSupply = 0;
	size_t _ramCapacity = 0;

public:
	Computer() = delete;
	Computer(const char* videoCardModel, double cpuPower, size_t powerSupply, size_t ramCapacity);

	Computer(const Computer& other);
	Computer& operator=(const Computer& other);

	Computer(Computer&& other) noexcept;
	Computer& operator=(Computer&& other) noexcept;

	virtual ~Computer();

	void setCpuPower(double cpuPower);
	void setVideoCardModel(const char* videoCardModel);
	void setPowerSupply(size_t poweSupply);
	void setRamCapacity(size_t ramCapacity);

	virtual void printType() const = 0;
	virtual void printPeripheralDevices() const = 0;

private:
	void free();
	void copyFrom(const Computer& other);
	void moveFrom(Computer&& other);
};

