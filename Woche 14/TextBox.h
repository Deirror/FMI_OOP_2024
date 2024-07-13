#pragma once
#include "Box.h"
class TextBox : public Box
{
public:
	TextBox(const std::string& name, float height, float width);

	std::string interact() const override;

	Item* clone() const override;

	ItemType getItemType() const override;
};

