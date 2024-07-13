#include "Box.h"
#include "itemTypes.h"

Box::Box(const std::string& name, float height, float width)
	: Item(name, height, width)
{
}

std::string Box::interact() const
{
	return "typing in the box...";
}
