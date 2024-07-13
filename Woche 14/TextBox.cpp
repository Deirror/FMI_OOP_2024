#include "TextBox.h"
#include "itemTypes.h"

TextBox::TextBox(const std::string& name, float height, float width)
	: Box(name, height, width)
{
}

std::string TextBox::interact() const
{
	return Box::interact() + "but it is just random text";
}

Item* TextBox::clone() const
{
	return new TextBox(*this);
}

ItemType TextBox::getItemType() const
{
	return ItemType::TextBox;
}
