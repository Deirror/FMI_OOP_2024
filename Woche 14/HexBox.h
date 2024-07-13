#pragma once
#include "Box.h"
class HexBox : public Box
{
public:
	HexBox(const std::string& name, float height, float width);

	std::string interact() const override;

	Item* clone() const override;

	ItemType getItemType() const override;
};

