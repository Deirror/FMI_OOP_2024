#pragma once
#include "Button.h"
class CheckButton : public Button
{
public:
	CheckButton(const std::string& name, float height, float width);

	Item* clone() const override;

	ItemType getItemType() const override;

	void hitCheckBox() const;

	bool getIsChecked() const;

private:
	mutable bool isChecked = false;
};

