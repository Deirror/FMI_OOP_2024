#pragma once
#include "Event.h"
#define MAX_DIFF_IN_MINUTES 2

class SimpleEvent : public Event
{
public:
	SimpleEvent() = delete;
	SimpleEvent(unsigned short hoursStart, unsigned short minutesStart, unsigned short hoursEnd, unsigned short minutesEnd);

	bool isInAntract(const Time& other) const override;

	Event* clone() const override;

	bool isInInterval() const override;
};

