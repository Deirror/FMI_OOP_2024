#pragma once
#include <iostream>
#include <exception>
#define DEF_CAP 4

template <typename T>
class Queue
{
private:
	T* data = nullptr;

	size_t size;
	size_t capacity;

	size_t put;
	size_t get;

public:
	Queue();

	Queue(const Queue<T>& other);
	Queue<T>& operator=(const Queue<T>& other);

	Queue(Queue<T>&& other) noexcept;
	Queue<T>& operator=(Queue<T>&& other) noexcept;

	void push(const T& other);
	void push(T&& other);
	void pop();

	bool isEmpty() const;
	const T& peek() const;

	void print() const;

	~Queue();

private:
	void free();
	void copyFrom(const Queue<T>& other);
	void moveFrom(Queue<T>&& other);

	void resize(size_t newCapacity);
};

template<typename T>
Queue<T>::Queue() : size(0), capacity(DEF_CAP), put(0), get(0)
{
	data = new T[capacity];
}

template<typename T>
Queue<T>::Queue(const Queue<T>& other)
{
	copyFrom(other);
}

template<typename T>
Queue<T> & Queue<T>::operator=(const Queue<T>& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

template<typename T>
Queue<T>::Queue(Queue<T>&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

template<typename T>
void Queue<T>::push(const T& other)
{
	if (size == capacity)
		resize(capacity*2);

	data[put] = other;
	(++put) %= capacity;
	size++;
}

template<typename T>
void Queue<T>::push(T&& other)
{
	if (size == capacity)
		resize(capacity*2);

	data[put] = std::move(other);
	(++put) %= capacity;
	size++;
}

template<typename T>
void Queue<T>::pop()
{
	if (size == 0)
		throw std::exception("Empty queue!");

	if (size == capacity / 4 && capacity > DEF_CAP)
		resize(capacity / 2);

	(++get) %= capacity;
	size--;
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return (size == 0);
}

template<typename T>
const T & Queue<T>::peek() const
{
	if (isEmpty())
		throw std::exception("Empty queue!");

	return data[get];
}

template<typename T>
void Queue<T>::print() const
{
	for (int i = get; i < put; i++)
	{
		std::cout << data[i] << ' ';
	}

}

template<typename T>
Queue<T>::~Queue()
{
	free();
}

template<typename T>
void Queue<T>::free()
{
	delete[] data;
	data = nullptr;
	size = capacity = 0;
	put = get = 0;
}

template<typename T>
void Queue<T>::copyFrom(const Queue<T>& other)
{
	size = other.size;
	capacity = other.capacity;

	data = new T[capacity];

	for (int i = 0; i < size; i++)
	{
		data[i] = other.data[i];
	}
}

template<typename T>
void Queue<T>::moveFrom(Queue<T>&& other)
{
	size = other.size;
	capacity = other.capacity;

	other.size = other.capacity = 0;

	data = other.data;
	other.data = nullptr;
}

template<typename T>
void Queue<T>::resize(size_t newCapacity)
{
	T* newData = new T[newCapacity];

	for (int i = 0; i < size; i++)
	{
		newData[i] = data[get];
		(++get) %= capacity;
	}

	delete[] data;
	data = newData;
	capacity = newCapacity;
	put = size;
	get = 0;
}
