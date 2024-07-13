#pragma once
#include "Item.h"

//Design Pattern : Factory
Item* itemFactory(ItemType type, float height, float width);