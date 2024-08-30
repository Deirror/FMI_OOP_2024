#pragma once
#include "Order.h"
#include "StringVector.h"

class Restaurant
{
private:
	char _name[MAX_LEN]{};
	List _products;

public:
	Restaurant() = default;
	Restaurant(const char* name, const List& products);

	void receiveOrder(const Order& order);

	void addProduct(const String& product);

	void setName(const char* name);
	void setProducts(const List& products);

	const char* getName() const;
	const List& getProducts() const;

	bool contains(const String& product);

};

