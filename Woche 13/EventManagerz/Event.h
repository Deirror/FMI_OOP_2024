#pragma once
#include "Time.h"

class Event
{
protected: 
	Time start;
	Time end;

	static const unsigned short MINUTES_IN_HOUR;

	void swapIfNeeded();

public:
	Event() = default;
	Event(unsigned short hoursStart, unsigned short minutesStart, unsigned short hoursEnd, unsigned short minutesEnd);

	bool isBetweenTimes(const Time& other) const;

	virtual bool isInAntract(const Time& other) const = 0;

	virtual bool isInInterval() const = 0;

	virtual Event* clone() const = 0;

	virtual ~Event() = default;
};

