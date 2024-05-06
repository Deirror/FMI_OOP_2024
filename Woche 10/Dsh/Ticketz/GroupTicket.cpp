#include "GroupTicket.h"

GroupTicket::GroupTicket(const String & playName, double originalPrice) : Ticket(playName, originalPrice)
{
}

double GroupTicket::getProceForGroup() const
{
	return getPrice() / 5.0;
}

void GroupTicket::printTicket() const
{
	std::cout << getPlayName() << getProceForGroup() << std::endl;	
}
