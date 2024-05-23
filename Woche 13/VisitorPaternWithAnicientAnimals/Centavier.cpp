#include "Centavier.h"

bool Centavier::fightWith(const AncientAnimal * obj) const
{
	return obj->figthWithCentavier(this);
}

bool Centavier::figthWithMinotavier(const Minotavier * obj) const
{
	return true;
}

bool Centavier::figthWithCentavier(const Centavier * obj) const
{
	return false;
}

bool Centavier::figthWithSfincs(const Sfincs * obj) const
{
	return false;
}
