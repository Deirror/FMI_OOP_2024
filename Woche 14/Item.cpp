#include "Item.h"

Item::Item(const std::string& name, float height, float width)
{
	setHeight(height);
	setWidth(width);
	setName(name);
}

bool Item::isHeightValid(float height) const
{
	return (height >= MIN_SIZE);
}

bool Item::isWidthValid(float width) const
{
	return (width >= MIN_SIZE);
}

bool Item::isNameValid(const std::string& name) const
{
	return(name.length() >= MIN_LEN_NAME);
}

void Item::setName(const std::string& name)
{
	if (!isNameValid(name))
		throw std::invalid_argument("Item::setName() Invalid Name");

	this->name = name;
}

void Item::setHeight(float height)
{
	if(!isHeightValid(height))
		throw std::invalid_argument("Item::setHeight() Invalid Height");

	this->height = height;
}

void Item::setWidth(float width)
{
	if (!isWidthValid(width))
		throw std::invalid_argument("Item::setWidth() Invalid Width");

	this->width = width;
}

const std::string& Item::getName() const
{
	return name;
}

float Item::getHeight() const
{
	return height;
}

float Item::getWidth() const
{
	return width;
}