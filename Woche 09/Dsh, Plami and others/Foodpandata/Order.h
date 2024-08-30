#pragma once
#include "StringVector.h"
#define MAX_LEN 26

typedef  StringVector List;

class Order
{
private:
	char _restaurantName[MAX_LEN]{};
	size_t _productsCount = 0;
	List _products;

	mutable size_t _deliveryInMinutes = 0;
	void calculateDeliveryInMinutes() const;

public:
	Order() = default;
	Order(const char* restaurantName, const List& products);

	void addProduct(const String& product);

	void setRestaurantName(const char* restaurantName);
	void setProductCount(size_t productsCount);
	void setProducts(const List& products);

	const char* getRestaurantName() const;
	size_t getProductsCount() const;
	const List& getProducts() const;
	size_t getDeliveryInMinutes() const;

	
};

