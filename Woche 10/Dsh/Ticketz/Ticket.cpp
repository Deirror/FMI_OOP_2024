#include "Ticket.h"

Ticket::Ticket(const String & playName, double price)
{
	setPrice(price);
	setPlayName(playName);
}

void Ticket::setPlayName(const String & playName)
{
	if (!strlen(playName.c_string()))
		throw std::exception("Nullptr");

	_playName = playName;
}

void Ticket::setPrice(double price)
{
	if (price < 0.)
		throw std::exception("Negative number");

	_price = price;
}

const String & Ticket::getPlayName() const
{
	return _playName;
}

double Ticket::getPrice() const
{
	return _price;
}

void Ticket::printTicket() const
{
	std::cout << _playName << std::endl << _price << std::endl << std::endl;
}
