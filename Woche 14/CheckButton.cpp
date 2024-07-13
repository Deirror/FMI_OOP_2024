#include "CheckButton.h"
#include "itemTypes.h"

CheckButton::CheckButton(const std::string& name, float height, float width)
	: Button(name, height, width)
{
}

Item* CheckButton::clone() const
{
	return new CheckButton(*this);
}

ItemType CheckButton::getItemType() const
{
	return ItemType::CheckButton;
}

void CheckButton::hitCheckBox() const
{
	isChecked = isChecked ? false : true;
}

bool CheckButton::getIsChecked() const
{
	return isChecked;
}
