#pragma once
#include "Order.h"
#include "Restaurant.h"
#include "String.h"

class Foodpanda
{
private:
	Restaurant* _restaurants = nullptr;

	size_t _count = 0;
	size_t _capacity = 0;
public:
	Foodpanda();
	Foodpanda(const Restaurant* restaurants, size_t count);

	Foodpanda(const Foodpanda& other);
	Foodpanda& operator=(const Foodpanda& other);

	Foodpanda(Foodpanda&& other) noexcept;
	Foodpanda& operator=(Foodpanda&& other) noexcept;

	void addProductToRestaurant(const String& product, const char* restaurant);
	void addRestaurant(const Restaurant& restaurant);

	void addOrderToRestaurant(const Order& order);

	void setCount(size_t count);
	void setRestaurants(const Restaurant* restaurants, size_t count);
	const Restaurant* getRestaurants() const;
	size_t getCount() const;
	size_t getCapacity() const;

	bool contains(const char* restaurant, size_t& index);

private:
	void free();
	void copyFrom(const Foodpanda& other);
	void moveFrom(Foodpanda&& other);

	void resize(size_t newSize);
};


