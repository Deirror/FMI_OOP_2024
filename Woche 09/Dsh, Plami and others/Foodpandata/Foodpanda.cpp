#include "Foodpanda.h"
#pragma warning (disable : 4996)

static unsigned roundToPowerOfTwo(int index)
{
	short times = 3;

	while (index - (1 << times++) >= 0);

	return (1 << --times);
}

Foodpanda::Foodpanda()
{
	resize(DEFUALT_CAPACITY);
}

Foodpanda::Foodpanda(const Restaurant* restaurants, size_t count)
{
	setCount(count);

	setRestaurants(restaurants, count);
}

Foodpanda::Foodpanda(const Foodpanda & other)
{
	copyFrom(other);
}

Foodpanda & Foodpanda::operator=(const Foodpanda & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Foodpanda::Foodpanda(Foodpanda && other) noexcept
{
	moveFrom(std::move(other));
}

Foodpanda & Foodpanda::operator=(Foodpanda && other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void Foodpanda::addProductToRestaurant(const String & product, const char* restaurant)
{
	size_t index = 0;

	if (!contains(restaurant, index))
		throw std::exception("Name doesn't exist in list");

	_restaurants[index].addProduct(product);
}

void Foodpanda::addRestaurant(const Restaurant & restaurant)
{
	if (_count == _capacity)
		resize(roundToPowerOfTwo(_count + 1));

	_restaurants[_count++] = restaurant;
}

void Foodpanda::addOrderToRestaurant(const Order & order)
{
	size_t index = 0;

	if (!contains(order.getRestaurantName(), index))
		throw std::exception("Doesn't contain restaurant");

	_restaurants[index].receiveOrder(order);
}

void Foodpanda::setCount(size_t count)
{
	_count = count;
}

void Foodpanda::setRestaurants(const Restaurant* restaurants, size_t count)
{
	if (!restaurants)
		throw std::exception("Nullptr");

	delete[] _restaurants;

	_capacity = roundToPowerOfTwo(count);
	_count = count;
	_restaurants = new Restaurant[_capacity];

	for (int i = 0; i < count; i++)
	{
		_restaurants[i] = restaurants[i];
	}
}

const Restaurant* Foodpanda::getRestaurants() const
{
	return _restaurants;
}

size_t Foodpanda::getCount() const
{
	return _count;
}

size_t Foodpanda::getCapacity() const
{
	return _capacity;
}

bool Foodpanda::contains(const char* restaurant, size_t& index)
{
	for (int i = 0; i < _count; i++)
	{
		if (strcmp(restaurant, _restaurants[i].getName()) == 0)
		{
			index = i;
			return true;
		}
	}

	return false;
}

void Foodpanda::free()
{
	delete[] _restaurants;

	_restaurants = nullptr;

	_count = _capacity = 0;
}

void Foodpanda::copyFrom(const Foodpanda & other)
{
	_count = other._count;
	_capacity = other._capacity;

	_restaurants = new Restaurant[_capacity];

	for (int i = 0; i < _count; i++)
	{
		_restaurants[i] = other._restaurants[i];
	}
}

void Foodpanda::moveFrom(Foodpanda && other)
{
	_count = other._count;
	_capacity = other._capacity;

	other._count = other._capacity = 0;

	_restaurants = other._restaurants;

	delete[] other._restaurants;
}

void Foodpanda::resize(size_t newCapacity)
{
	if (newCapacity <= _capacity)
		return;

	Restaurant* newRestaurants = new Restaurant[newCapacity];

	for (int i = 0; i < _count; i++)
	{
		newRestaurants[i] = _restaurants[i];
	}

	delete[] _restaurants;
	_restaurants = newRestaurants;
	_capacity = newCapacity;
} 
