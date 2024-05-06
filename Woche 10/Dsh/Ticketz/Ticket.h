#pragma once
#include "String.h"

class Ticket
{
private:
	String _playName;
	double _price = 0.;

public:
	Ticket() = default;
	Ticket(const String& playName, double price);

	void setPlayName(const String& playName);
	void setPrice(double price);

	const String& getPlayName() const;
	double getPrice() const;

	void printTicket() const;
};

