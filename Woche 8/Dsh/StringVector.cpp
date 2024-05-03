#include "StringVector.h"
#include <cstring>
#include <exception>

static unsigned roundToPowerOfTwo(int index)
{
	short times = 3;

	while (index - (1 << times++) >= 0);

	return (1 << --times);
}

StringVector::StringVector()
{
	resize(DEFUALT_CAPACITY);
}

StringVector::StringVector(const StringVector & other)
{
	copyFrom(other);
}

StringVector & StringVector::operator=(const StringVector & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

StringVector::~StringVector()
{
	delete[] _strings;
}

void StringVector::push_back(const String& other)
{
	if (_size == _capacity)
		resize(roundToPowerOfTwo(_size + 1));

	_strings[_size++] = other;
}

void StringVector::pop_back()
{
	if (_size == 0)
		throw std::exception("Empty");

	_strings[_size--] = nullptr;
}

void StringVector::insert(const String& string, size_t index)
{
	if(index > _size)
		throw std::exception("Out of range");

	if (_size == _capacity)
		resize(roundToPowerOfTwo(_size + 1));

	for (int i = _size; i > (int)index; i--)
	{
		_strings[i] = _strings[i - 1];
	}

	_strings[index] = string;

	_size++;
}

void StringVector::erase(size_t index)
{
	if (index >= _size)
		throw std::exception("Out of range");

	for (int i = index; i < _size - 1; i++)
	{
		_strings[i] = _strings[i + 1];
	}

	_strings[_size - 1] = nullptr;

	_size--;
}

void StringVector::clear()
{
	delete[] _strings;

	_size = 0;

	resize(DEFUALT_CAPACITY);
}

String & StringVector::operator[](size_t index)
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");

	return _strings[index];
}

const String & StringVector::operator[](size_t index) const
{
	if (index >= _size)
		throw std::out_of_range("Index out of range");

	return _strings[index];
}

bool StringVector::empty()
{
	return (_size == 0);
}

size_t StringVector::getSize() const
{
	return _size;
}

void StringVector::free()
{
	delete[] _strings;

	_strings = nullptr;
	_size = _capacity = 0;
}

void StringVector::copyFrom(const StringVector & other)
{
	_size = other._size;
	_capacity = other._capacity;

	_strings = new String[_capacity]{};

	for (int i = 0; i < _size; i++)
	{
		_strings[i] = other._strings[i];
	}
}

void StringVector::resize(size_t newCapacity)
{
	if (newCapacity <= _capacity)
		return;

	String* newStrings = new String[newCapacity]{};

	for (int i = 0; i < _size; i++)
	{
		newStrings[i] = _strings[i];
	}

	delete[] _strings;
	_strings = newStrings;
	_capacity = newCapacity;
}
