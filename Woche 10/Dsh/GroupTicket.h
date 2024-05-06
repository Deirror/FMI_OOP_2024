#pragma once
#include "Ticket.h"

class GroupTicket : Ticket
{
public:
	GroupTicket() = default;
	GroupTicket(const String& playName, double originalPrice);

	double getProceForGroup() const;

	void printTicket() const override;
};

