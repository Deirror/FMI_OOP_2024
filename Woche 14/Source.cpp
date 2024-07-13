#include <iostream>
#include"WindowComponents.h"
#include "itemFactory.h"
#include "itemTypes.h"

int main()
{
	WindowComponents wc("Doomz");

	wc.addComponent(itemFactory(ItemType::Label, 1, 1));
	wc.addComponent(itemFactory(ItemType::HexBox, 2, 2));

	wc.interactWithAll();
	wc.seeAllComponentsTypes();

	wc.removeComponentByIndex(0);

	wc.printNamesOfControls();

	return 0;
}