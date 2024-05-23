#include "Sfincs.h"

bool Sfincs::fightWith(const AncientAnimal * obj) const
{
	return obj->figthWithSfincs(this);
}

bool Sfincs::figthWithMinotavier(const Minotavier * obj) const
{
	return false;
}

bool Sfincs::figthWithCentavier(const Centavier * obj) const
{
	return true;
}

bool Sfincs::figthWithSfincs(const Sfincs * obj) const
{
	return false;
}


