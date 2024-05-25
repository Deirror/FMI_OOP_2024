#include "EventManager.h"
#include <utility>

EventManager::EventManager() : size(0), capacity(DEF_CAP)
{
	data = new Event * [capacity] {nullptr};
}

EventManager::EventManager(const EventManager& other)
{
	copyFrom(other);
}

EventManager& EventManager::operator=(const EventManager& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

EventManager::EventManager(EventManager&& other) noexcept
{
	moveFrom(std::move(other));
}

EventManager& EventManager::operator=(EventManager&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

EventManager::~EventManager()
{
	free();
}

void EventManager::add(Event* other)
{
	if (size == capacity)
		resize(capacity * 2);

	data[size++] = other;
	other = nullptr;
}

void EventManager::add(const Event& other)
{
	add(other.clone());
}

bool EventManager::isBusy(unsigned short hrs, unsigned short mins) const
{
	Time myTime(hrs, mins);

	for (int i = 0; i < size; i++)
	{
		if (data[i]->isBetweenTimes(myTime))
			return true;
	}

	return false;
}

size_t EventManager::ongoingEvents(unsigned short hours) const
{
	Time myTime(hours);

	size_t count = 0;

	for (int i = 0; i < size; i++)
	{
		if (data[i]->isBetweenTimes(myTime))
		{
			if (!data[i]->isInAntract(myTime))
				count++;
		}
	}

	return count;
}

void EventManager::free()
{
	for (int i = 0; i < size; i++)
	{
		delete data[i];
		data[i] = nullptr;
	}

	delete[] data;
	data = nullptr;

	size = capacity = 0;
}

void EventManager::copyFrom(const EventManager& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new Event * [capacity] {nullptr};

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i]->clone();
	}
}

void EventManager::moveFrom(EventManager&& other)
{
	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;

	data = other.data;

	other.data = nullptr;
}

void EventManager::resize(size_t newCapacity)
{
	Event** temp = new Event * [newCapacity] {nullptr};

	for (int i = 0; i < size; i++)
	{
		temp[i] = data[i];
	}

	delete[] data;
	data = temp;

	capacity = newCapacity;
}
