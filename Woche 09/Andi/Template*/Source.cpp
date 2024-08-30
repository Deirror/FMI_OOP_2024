#include <iostream>
#include "PointerCollection.h"

int main()
{
	PointerCollection<int> pc;

	pc.pushBack(1);
	pc.pushBack(2);
	pc.pushBack(2);
	pc.pushBack(2);
	pc.pushBack(2);
	pc.pushBack(5);
	pc.pushBack(3);
	pc.pushBack(4);

	std::cout << pc.isEmpty() << std::endl;
	std::cout << pc.contains(3) << std::endl;

	std::cout << pc.getSize() << " " << pc.getCapacity();

	pc.pushBack(4);

	std::cout << pc.getSize() << " " << pc.getCapacity();

	pc.setAtIndex(0, 0);

	return 0;
}