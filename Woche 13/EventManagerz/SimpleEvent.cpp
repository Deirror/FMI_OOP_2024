#include "SimpleEvent.h"
#include <exception>

SimpleEvent::SimpleEvent(unsigned short hoursStart, unsigned short minutesStart, unsigned short hoursEnd, unsigned short minutesEnd)
	: Event(hoursStart,minutesStart,hoursEnd,minutesEnd)
{
	if (!isInInterval())
		throw std::exception("Out of range");
}

bool SimpleEvent::isInAntract(const Time& other) const
{
	return false;
}

Event* SimpleEvent::clone() const
{
	return new SimpleEvent(*this);
}

bool SimpleEvent::isInInterval() const
{
	return ((end.convertToMinutes() - start.convertToMinutes()) <= MAX_DIFF_IN_MINUTES * Event::MINUTES_IN_HOUR);
}
