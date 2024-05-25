#include "Event.h"

const unsigned short Event::MINUTES_IN_HOUR = 60;

static void swapTimes(Time& lhs, Time& rhs)
{
	Time buff = lhs;
	lhs = rhs;
	rhs = buff;
}

void Event::swapIfNeeded()
{
	if (start.convertToMinutes() > end.convertToMinutes())
		swapTimes(start, end);

}

Event::Event(unsigned short hoursStart, unsigned short minutesStart, unsigned short hoursEnd, unsigned short minutesEnd)
	: start(hoursStart, minutesStart), end(hoursEnd, minutesEnd)
{
	swapIfNeeded();
}

bool Event::isBetweenTimes(const Time& other) const
{
	return (start.convertToMinutes() <= other.convertToMinutes() && other.convertToMinutes() <= end.convertToMinutes());
}
