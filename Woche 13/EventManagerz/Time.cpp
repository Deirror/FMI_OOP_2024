#include "Time.h"
#include <exception>

Time::Time(unsigned short _hours) : minutes(0)
{
	setHours(_hours);
}

Time::Time(unsigned short _hours, unsigned short _minutes)
{
	setHours(_hours);
	setMinutes(_minutes);
}

void Time::setHours(unsigned short _hours)
{
	if (_hours >= 24)
		throw std::exception("Out of range!");

	hours = _hours;
}

void Time::setMinutes(unsigned short _minutes)
{
	if (_minutes >= 60)
		throw std::exception("Out of range!");

	minutes = _minutes;;
}

unsigned short Time::getHours() const
{
	return hours;
}

unsigned short Time::getMinutes() const
{
	return minutes;
}

unsigned short Time::convertToMinutes() const
{
	return 60 * hours + minutes;
}


