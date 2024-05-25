#pragma once
#include "Event.h"
#define DEF_CAP 8

class EventManager
{
private:
	Event** data = nullptr;

	size_t size = 0;
	size_t capacity = 0;

public:
	EventManager();

	EventManager(const EventManager& other);
	EventManager& operator=(const EventManager& other);

	EventManager(EventManager&& other) noexcept;
	EventManager& operator=(EventManager&& other) noexcept;

	~EventManager();

	void add(Event* other);
	void add(const Event& other);

	bool isBusy(unsigned short hrs, unsigned short mins) const;

	size_t ongoingEvents(unsigned short hours) const;

private:
	void free();
	void copyFrom(const EventManager& other);
	void moveFrom(EventManager&& other);

	void resize(size_t newCapacity);
};

