#pragma once
#include <vector>
#include "polymorhic_ptr.hpp"
#include "Item.h"

//Design Pattern : Composite (kinda)
class WindowComponents
{
public:
	WindowComponents(const std::string& winName);

	~WindowComponents();

	void addComponent(Item* item);

	void removeComponent(const std::string& name);
	void removeComponentByIndex(size_t index);

	void interactByIndex(size_t index) const;
	void interactWithAll() const;

	void printNamesOfControls() const;

	void seeAllComponentsTypes() const;

	void seeComponentTypeByIndex(size_t index) const;

	size_t getCountOfComponents() const;

private:
	int find(const std::string& name) const;

	std::string winName;

	std::vector<polymorphic_ptr<Item>> components;

	std::vector<unsigned short> countOfComponents;
};

