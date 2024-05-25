#include "EventWithIntermission.h"
#include <exception>

EventWithIntermission::EventWithIntermission(unsigned short hoursStart, unsigned short minutesStart, unsigned short hoursEnd, unsigned short minutesEnd, unsigned short _antract)
	: Event(hoursStart, minutesStart, hoursEnd, minutesEnd)
{
	setAntract(_antract);

	if (end.convertToMinutes() - start.convertToMinutes() < antract)
		throw std::exception("Too small");

	if (!isInInterval())
		throw std::exception("Out of range");
}

void EventWithIntermission::setAntract(unsigned short _antract)
{
	if (_antract < MIN_ANTRACT || _antract > MAX_ANTRACT)
		throw std::exception("Out of range");

	antract = _antract;

}

unsigned short EventWithIntermission::getAntract() const
{
	return antract;
}

bool EventWithIntermission::isInAntract(const Time& other) const
{
	return ((end.convertToMinutes() - antract) <= other.convertToMinutes() && other.convertToMinutes() <= end.convertToMinutes());
}


Event* EventWithIntermission::clone() const
{
	return new EventWithIntermission(*this);
}

bool EventWithIntermission::isInInterval() const
{
	return ((end.convertToMinutes() - start.convertToMinutes()) <= MAX_DIFF_IN_MINUTES * Event::MINUTES_IN_HOUR);
}
