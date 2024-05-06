#include <iostream>
#include "PointerToPointerCollection.h"

int main()
{
	PointerToPointerCollection<int> ppc;

	ppc.addAtFirstFreeIndex(1);
	ppc.addAtFirstFreeIndex(2);
	ppc.addAtFirstFreeIndex(3);
	ppc.addAtFirstFreeIndex(4);
	ppc.addAtFirstFreeIndex(5);
	ppc.addAtFirstFreeIndex(4);
	ppc.addAtFirstFreeIndex(4);
	ppc.removeAt(0);
	ppc.addAtFirstFreeIndex(-1);
	
	ppc.setAtIndex(10, 10);

	return 0;
}