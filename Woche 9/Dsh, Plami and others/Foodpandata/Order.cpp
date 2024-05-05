#include "Order.h"
#pragma warning (disable : 4996)

Order::Order(const char* restraurantName, const List& products)
{
	setRestaurantName(restraurantName);

	setProductCount(products.getSize());

	setProducts(products);

	calculateDeliveryInMinutes();
}

void Order::addProduct(const String & product)
{
	_products.push_back(product);

	calculateDeliveryInMinutes();
}

void Order::setRestaurantName(const char* restaurantName)
{
	if (!restaurantName)
		throw std::exception("Nullptr");

	if (strlen(restaurantName) >= MAX_LEN)
		throw std::exception("Too long name");

	strcpy(_restaurantName, restaurantName);
}

void Order::setProductCount(size_t productsCount)
{
	_productsCount = productsCount;
}

void Order::setProducts(const List& products)
{
	_products = products;
}

const char* Order::getRestaurantName() const
{
	return _restaurantName;
}

size_t Order::getProductsCount() const
{
	return _productsCount;
}

const List & Order::getProducts() const
{
	return _products;
}

size_t Order::getDeliveryInMinutes() const
{
	return _deliveryInMinutes;
}

void Order::calculateDeliveryInMinutes() const
{
	_deliveryInMinutes = 0;

	_deliveryInMinutes = _productsCount + _products.getLengthsOfStrings();
}
