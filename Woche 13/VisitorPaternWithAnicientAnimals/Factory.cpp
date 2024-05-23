#include "Factory.h"
#include "Centavier.h"
#include "Minotavier.h"
#include "Sfincs.h"

AncientAnimal * animalFacotry(unsigned short type)
{
	switch (type)
	{
	case 0:
	{
		return new Minotavier();
	}
	case 1:
	{
		return new Centavier();
	}
	case 2:
	{
		return new Sfincs();
	}
	}
}
