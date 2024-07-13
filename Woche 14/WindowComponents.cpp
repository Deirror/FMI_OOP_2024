#include "WindowComponents.h"
#include "SingletonWindowsNames.h"
#include <iostream>
#include <string>
#include "itemTypes.h"

static std::string stringEnumType(ItemType type)
{
	switch (type)
	{
	case ItemType::Label:
		return "Label";
	case ItemType::Button:
		return "Button";
	case ItemType::CheckButton:
		return "CheckButton";
	case ItemType::TextBox:
		return "TextBox";
	case ItemType::HexBox:
		return "HexBox";
	default:
		break;
	}

	return {};
}

WindowComponents::WindowComponents(const std::string& winName)
{
	SingletonWindowsNames& ref = SingletonWindowsNames::getInstance();

	ref.push_winName(winName);

	this->winName = winName;

	int size = static_cast<int>(ItemType::Count);

	for (int i = 0; i < size; i++)
	{
		countOfComponents.push_back(1);
	}
}

WindowComponents::~WindowComponents()
{
	SingletonWindowsNames& ref = SingletonWindowsNames::getInstance();

	ref.pop_winName(winName);
}

void WindowComponents::addComponent(Item* item)
{
	ItemType type = item->getItemType();

	int index = static_cast<int>(type);
	
	item->setName(stringEnumType(type) + std::to_string(countOfComponents[index]++));

	components.push_back(item);
}

void WindowComponents::removeComponent(const std::string& name)
{
	int index = find(name);

	if (index == -1)
		return;

	removeComponentByIndex(index);
}

void WindowComponents::removeComponentByIndex(size_t index)
{
	components.erase(components.begin() + index);
}

void WindowComponents::interactByIndex(size_t index) const
{
	std::cout << components[index]->interact();
}

void WindowComponents::interactWithAll() const
{
	for (int i = 0; i < components.size(); i++)
	{
		interactByIndex(i);
		std::cout << '\n';
	}
}

void WindowComponents::printNamesOfControls() const
{
	for (int i = 0; i < components.size(); i++)
	{
		std::cout << components[i]->getName() << '\n';
	}
}

void WindowComponents::seeAllComponentsTypes() const
{
	for (int i = 0; i < components.size(); i++)
	{
		seeComponentTypeByIndex(i);
		std::cout << '\n';
	}
}

void WindowComponents::seeComponentTypeByIndex(size_t index) const
{
	std::cout << stringEnumType(components[index]->getItemType());
}

size_t WindowComponents::getCountOfComponents() const
{
	return components.size();
}

int WindowComponents::find(const std::string& name) const
{
	for (int i = 0; i < components.size(); i++)
	{
		if (name == components[i]->getName())
			return i;
	}

	return -1;
}
