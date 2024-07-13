#include "Button.h"
#include "itemTypes.h"

Button::Button(const std::string& name, float height, float width)
	: Item(name, height, width)
{
}

Item* Button::clone() const
{
	return new Button(*this);
}

std::string Button::interact() const
{
	return "Clicking on button :))";
}

ItemType Button::getItemType() const
{
	return ItemType::Button;
}
