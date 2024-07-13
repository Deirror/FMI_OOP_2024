#include "Label.h"
#include "itemTypes.h"

Label::Label(const std::string& name, float height, float width)
	: Item(name, height, width)
{
}

Item* Label::clone() const
{
	return new Label(*this);
}

std::string Label::interact() const
{
	return "just clicking on a label, nothing special here...";
}

ItemType Label::getItemType() const
{
	return ItemType::Label;
}
