#pragma once
#include "Item.h"

class Button : public Item
{
public:
	Button(const std::string& name, float height, float width);

	Item* clone() const override;

	std::string interact() const override;

	ItemType getItemType() const override;
};

