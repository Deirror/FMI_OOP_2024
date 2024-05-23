#include "Minotavier.h"

bool Minotavier::fightWith(const AncientAnimal * obj) const
{
	return obj->figthWithMinotavier(this);
}

bool Minotavier::figthWithMinotavier(const Minotavier * obj) const
{
	return false;
}

bool Minotavier::figthWithCentavier(const Centavier * obj) const
{
	return false;
}

bool Minotavier::figthWithSfincs(const Sfincs * obj) const
{
	return true;
}
