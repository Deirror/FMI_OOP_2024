#include "EventWithFixedIntermission.h"
#include <exception>

EventWithFixedIntermission::EventWithFixedIntermission(unsigned short hoursStart, unsigned short minutesStart, unsigned short hoursEnd, unsigned short minutesEnd)
	: Event(hoursStart, minutesStart, hoursEnd, minutesEnd)
{
	if (end.convertToMinutes() - start.convertToMinutes() < antract)
		throw std::exception("Too small");

	if (!isInInterval())
		throw std::exception("Out of range");
}

Event* EventWithFixedIntermission::clone() const
{
	return new EventWithFixedIntermission(*this);
}

bool EventWithFixedIntermission::isInAntract(const Time& other) const
{
	return (start.convertToMinutes() <= other.convertToMinutes() && other.convertToMinutes() <= start.convertToMinutes() + antract);
}

bool EventWithFixedIntermission::isInInterval() const
{
	return ((end.convertToMinutes() - start.convertToMinutes()) <= MAX_DIFF_IN_MINUTES * Event::MINUTES_IN_HOUR);;
}
