#pragma once
#include "Ticket.h"

class StudentTicket : Ticket
{
public:
	StudentTicket() = default;
	StudentTicket(const String& playName, double originalPrice);

	double getPriceForStudent() const;

	void printTicket() const override;
};

