#pragma once
#include <exception>
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! This version is the slowest, but the easiest !!!!!!!!!!!!!!!!!!
template <typename T>
class Queue
{

private:
	T* _data = nullptr;

	size_t _size = 0;
	size_t _capacity = 0;

	static constexpr short DEFAULT_CAPACITY = 8;

public:
	Queue();

	Queue(const Queue&);
	Queue& operator=(const Queue&);

	Queue(Queue&&) noexcept;
	Queue& operator=(Queue&&) noexcept;

	~Queue();

	void push(const T&);
	void push(T&&);
	void pop();
	const T& peek() const;

	bool isEmpty() const;
	void clear();

private:
	void free();
	void copyFrom(const Queue&);
	void moveFrom(Queue&&);

	void resize(size_t newCapacity);
};


template<typename T>
inline Queue<T>::Queue() : _size(0), _capacity(DEFAULT_CAPACITY)
{
	_data = new T[_capacity];
}

template<typename T>
inline Queue<T>::Queue(const Queue& other)
{
	copyFrom(other);
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

template<typename T>
inline Queue<T>::Queue(Queue&& other) noexcept
{
	moveFrom(std::move(other));
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(Queue&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

template<typename T>
inline Queue<T>::~Queue()
{
	delete[] _data;
}

template<typename T>
inline void Queue<T>::push(const T& other)
{
	if (_size == _capacity)
		resize(_capacity * 2);

	for (int i = _size - 1; i >= 0; i--)
	{
		_data[i + 1] = _data[i];
	}

	_data[0] = other;
	_size++;
}

template<typename T>
inline void Queue<T>::push(T&& other)
{
	if (_size == _capacity)
		resize(_capacity * 2);

	for (int i = _size - 1; i >= 0; i--)
	{
		_data[i + 1] = _data[i];
	}

	_data[0] = std::move(other);
	_size++;
}

template<typename T>
inline void Queue<T>::pop()
{
	if (_size == 0)
		throw std::exception("Empty queue");

	_size--;

	if (_size == _capacity / 4 && _capacity > DEFAULT_CAPACITY)
		resize(_capacity / 2);
}

template<typename T>
inline const T& Queue<T>::peek() const
{
	return _data[_size - 1];
}

template<typename T>
inline bool Queue<T>::isEmpty() const
{
	return (_size == 0);
}

template<typename T>
inline void Queue<T>::clear()
{
	free();

	_data = new T[_capacity];
}

template<typename T>
inline void Queue<T>::free()
{
	delete[] _data;
	_data = nullptr;
	_size = 0;
	_capacity = DEFAULT_CAPACITY;
}

template<typename T>
inline void Queue<T>::copyFrom(const Queue& other)
{
	_size = other._size;
	_capacity = other._capacity;

	_data = new T[_capacity];

	for (int i = 0; i < _size; i++)
	{
		_data[i] = other._data[i];
	}
}

template<typename T>
inline void Queue<T>::moveFrom(Queue&& other)
{
	_size = other._size;
	_capacity = other._capacity;

	other._size = other._capacity = 0;

	_data = other._data;

	other._data = nullptr;
}

template<typename T>
inline void Queue<T>::resize(size_t newCapacity)
{
	T* newData = new T[newCapacity];

	for (int i = 0; i < _size; i++)
	{
		newData[i] = _data[i];
	}

	delete[] _data;
	_data = newData;
	_capacity = newCapacity;
}
