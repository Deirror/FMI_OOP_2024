#include "StudentTicket.h"

StudentTicket::StudentTicket(const String & playName, double originalPrice) : Ticket(playName, originalPrice)
{

}

double StudentTicket::getPriceForStudent() const
{
	return getPrice() / 2.0;
}

void StudentTicket::printTicket() const
{
	std::cout << getPlayName() << getPriceForStudent() << std::endl;
}
