#include "Restaurant.h"
#pragma warning (disable : 4996)

Restaurant::Restaurant(const char * name, const List & products)
{
	setName(name);

	setProducts(products);
}

void Restaurant::receiveOrder(const Order & order)
{
	if (strcmp(_name, order.getRestaurantName()) != 0)
		throw std::exception("Names don't match");

	for (int i = 0; i < order.getProductsCount(); i++)
	{
		if (!contains(order.getProducts()[i]))
		{
			throw std::exception("Doesn't contain the product");
		}
	}
}

void Restaurant::addProduct(const String & product)
{
	_products.push_back(product);
}

void Restaurant::setName(const char * name)
{
	if (!name)
		throw std::exception("Nullptr");

	if (strlen(name) >= MAX_LEN)
		throw std::exception("Too long name");

	strcpy(_name, name);
}

void Restaurant::setProducts(const List & products)
{
	_products = products;
}

const char * Restaurant::getName() const
{
	return _name;
}

const List & Restaurant::getProducts() const
{
	return _products;
}

bool Restaurant::contains(const String & product)
{
	for (int i = 0; i < _products.getSize(); i++)
	{
		if (product == _products[i])
			return true;
	}

	return false;
}
