#include "String.h"
#include <cstring>
#include <exception>
#pragma warning (disable : 4996)
#include "String.h"

static unsigned roundToPowerOfTwo(int index)
{
	short times = 3;

	while (index - (1 << times++) >= 0);

	return (1 << --times);
}

String::String()
{
	resize(DEFUALT_CAPACITY);
}

String::String(const char * string)
{
	if (!string)
	{
		_string = nullptr;
		_length = 0;
		_capacity = 8;
	}
	else
	{
		_length = strlen(string);

		_capacity = roundToPowerOfTwo(_length);

		delete[] _string;

		_string = new char[_capacity + 1]{};

		strcpy(_string, string);
	}
}

String::String(const String & other)
{
	copyFrom(other);
}

String & String::operator=(const String & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

String & String::operator+=(const String & other)
{
	if (_length + other._length > _capacity)
		resize(_length + other._length);

	size_t index = 0;

	while (other._string[index])
	{
		_string[_length + index] = other._string[index++];
	}

	_length += other._length;

	return *this;
}

String::~String()
{
	delete[] _string;
}

const char * String::c_string() const
{
	return _string;
}

size_t String::getCapacity() const
{
	return _capacity;
}

size_t String::getLength() const
{
	return _length;
}

char & String::operator[](size_t index)
{
	if (index >= _length)
		throw std::out_of_range("Index out of range");

	return _string[index];
}

const char & String::operator[](size_t index) const
{
	if (index >= _length)
		throw std::out_of_range("Index out of range");

	return _string[index];
}

String::String(size_t stringLength)
{
	_capacity = roundToPowerOfTwo(stringLength);

	_string = new char[_capacity + 1] {};

	_length = 0;
}

void String::debug() const
{
	std::cout << _string << std::endl;
}

void String::free()
{
	delete[] _string;

	_string = nullptr;

	_length = _capacity = 0;
}

void String::copyFrom(const String & other)
{
	_length = other._length;
	_capacity = other._capacity;

	_string = new char[_capacity + 1] {};

	if(other._string)
	strcpy(_string, other._string);
}

void String::resize(size_t stringLength)
{
	if (stringLength <= _capacity)
		return;

	size_t newCapacity = roundToPowerOfTwo(stringLength);
	char* newString = new char[newCapacity + 1] {};

	if(_string)
	strcpy(newString, _string);

	delete[] _string;
	_string = newString;
	_capacity = newCapacity;
}

std::ostream & operator<<(std::ostream & os, const String & obj)
{
	os << obj._string << std::endl;

	return os;
}

std::istream & operator>>(std::istream & is, String & ref)
{
	char buff[1024]{};

	is.getline(buff, 1024);

	ref.free();

	ref._length = strlen(buff);

	ref._capacity = roundToPowerOfTwo(ref._length);

	ref._string = new char[ref._capacity + 1]{};

	strcpy(ref._string, buff);

	return is;
}

String operator+(const String & lhs, const String & rhs)
{
	String result(lhs.getLength() + rhs.getLength());

	result += lhs;
	result += rhs;

	return result;
}

bool operator==(const String & lhs, const String & rhs)
{
	return (strcmp(lhs.c_string(),rhs.c_string()) == 0);
}

bool operator!=(const String & lhs, const String & rhs)
{
	return !(lhs == rhs);
}

bool operator<(const String & lhs, const String & rhs)
{
	return (strcmp(lhs.c_string(), rhs.c_string()) < 0);
}

bool operator<=(const String & lhs, const String & rhs)
{
	return (strcmp(lhs.c_string(), rhs.c_string()) <= 0);
}

bool operator>(const String & lhs, const String & rhs)
{
	return (strcmp(lhs.c_string(), rhs.c_string()) > 0);
}

bool operator>=(const String & lhs, const String & rhs)
{
	return (strcmp(lhs.c_string(), rhs.c_string()) >= 0);
}
