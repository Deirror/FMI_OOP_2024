#include "HexBox.h"
#include "itemTypes.h"

HexBox::HexBox(const std::string& name, float height, float width)
	: Box(name, height, width)
{
}

std::string HexBox::interact() const
{
	return Box::interact() + "but it is 1A 00 23 79";
}

Item* HexBox::clone() const
{
	return new HexBox(*this);
}

ItemType HexBox::getItemType() const
{
	return ItemType::HexBox;
}
