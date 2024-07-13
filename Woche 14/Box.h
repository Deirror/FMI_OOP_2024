#pragma once
#include "Item.h"

class Box : public Item
{
public:
	Box(const std::string& name, float height, float width);

	std::string interact() const override;
};

