#pragma once
#include <string>
#include <stdexcept>
#define MIN_SIZE 0.5f
#define MIN_LEN_NAME 5

enum class ItemType;

class Item
{
public:
	Item(const std::string& name, float height, float width);

	virtual ~Item() = default;

	//Design Pattern : Prototype
	virtual Item* clone() const = 0;

	virtual std::string interact() const = 0;

	virtual ItemType getItemType() const = 0;

	void setName(const std::string& name);

	void setHeight(float height);
	void setWidth(float width);

	const std::string& getName() const;

	float getHeight() const;
	float getWidth() const;

protected:
	std::string name;

	float height = MIN_SIZE;
	float width = MIN_SIZE;

private:
	bool isHeightValid(float height) const;
	bool isWidthValid(float width) const;

	bool isNameValid(const std::string& name) const;

};