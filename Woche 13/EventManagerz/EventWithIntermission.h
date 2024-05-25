#pragma once
#include "Event.h"
#define MAX_DIFF_IN_MINUTES 6

class EventWithIntermission :
	public Event
{
private:
	static constexpr unsigned short MIN_ANTRACT = 30;
	static constexpr unsigned short MAX_ANTRACT = 60;

	unsigned short antract = 0;

public:
	EventWithIntermission() = delete;
	EventWithIntermission(unsigned short hoursStart, unsigned short minutesStart, unsigned short hoursEnd, unsigned short minutesEnd, unsigned short _antract);

	void setAntract(unsigned short _antract);
	unsigned short getAntract() const;

	bool isInAntract(const Time& other) const override;

	Event* clone() const override;

	bool isInInterval() const override;
};

