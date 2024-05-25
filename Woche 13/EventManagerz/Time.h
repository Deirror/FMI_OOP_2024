#pragma once
class Time
{
private:
	unsigned short hours = 0;
	unsigned short minutes = 0;

public:
	Time() = default;
	explicit Time(unsigned short _hours);
	Time(unsigned short _hours, unsigned short _minutes);

	void setHours(unsigned short _hours);
	void setMinutes(unsigned short _minutes);

	unsigned short getHours() const;
	unsigned short getMinutes() const;

	unsigned short convertToMinutes() const;
};

