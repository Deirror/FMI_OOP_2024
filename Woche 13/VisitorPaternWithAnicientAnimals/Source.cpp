#include <iostream>
#include <cstdlib>
#include "AncientAnimal.h"
#include "Factory.h"

int main()
{
	AncientAnimal** collection = new AncientAnimal*[15];

	for (int i = 0; i < 15; i++)
	{
		switch (rand() % 3)
		{
		case 0:	
		{
			collection[i] = animalFacotry(0);
			break;
		}
		case 1:
		{
			collection[i] = animalFacotry(1);
			break;
		}
		case 2:
		{
			collection[i] = animalFacotry(2);
			break;
		}
		}
	}

	size_t wonRounds = 0;

	size_t index = rand() % 15;

	for (int i = 0; i < 15; i++)
	{
		if (index != i)
		{
			if (collection[index]->fightWith(collection[i]))
				wonRounds++;
		}
	}

	std::cout << "Won rounds : " << wonRounds;

	return 0;
}