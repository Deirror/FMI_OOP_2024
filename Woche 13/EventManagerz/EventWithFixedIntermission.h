#pragma once
#include "Event.h"
#define MAX_DIFF_IN_MINUTES 4

class EventWithFixedIntermission : public Event
{
private:
	static constexpr unsigned short antract = 20;

public:
	EventWithFixedIntermission() = delete;
	EventWithFixedIntermission(unsigned short hoursStart, unsigned short minutesStart, unsigned short hoursEnd, unsigned short minutesEnd);

	Event* clone() const override;

	bool isInAntract(const Time& other) const override;

	bool isInInterval() const override;

};

