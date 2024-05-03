#include "StringPool.h"
#include <exception>
#pragma warning (disable : 4996)

static unsigned roundToPowerOfTwo(int index)
{
	short times = 3;

	while (index - (1 << times++) >= 0);

	return (1 << --times);
}

StringPool::StringPool()
{
	resize(DEFAULT_CAPACITY);
}

StringPool::StringPool(const StringPool & other)
{
	copyFrom(other);
}

StringPool & StringPool::operator=(const StringPool & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

void StringPool::StringNode::allocateString(const char * string)
{
	if (!string)
		throw std::exception("Nullptr");

	size_t length = strlen(string);

	_string = new char[length + 1]{};

	strcpy(_string, string);
}

StringPool::~StringPool()
{
	for (size_t i = 0; i < _size; i++)
		delete[] _nodes[i]._string;

	delete[] _nodes;
}

StringPool & StringPool::operator+=(const StringPool & other)
{
	for (int i = 0; i < other._size; i++)
	{
		bool isFound = false;
		int index = findString(other._nodes[i]._string, isFound);

		if(!isFound)
			insertString(other._nodes[i]._string, index);
	}

	return *this;
}

StringPool & StringPool::operator-=(const StringPool & other)
{
	for (int i = 0; i < other._size; i++)
	{
		removeString(other._nodes[i]._string);
	}

	return *this;
}

StringPool & StringPool::operator*=(const char * string)
{
	if (!string)
		throw std::exception("Nullptr");

	bool isFound = false;
	int index = findString(string, isFound);

	if (isFound)
		return *this;

	insertString(string, index);
	return *this;
}

StringPool & StringPool::operator/=(const char * string)
{
	removeString(string);

	return *this;
}

bool StringPool::operator[](const char * string)
{
	bool isFound = false;
	findString(string, isFound);

	return isFound;
}

void StringPool::free()
{
	for (size_t i = 0; i < _size; i++)
		delete[] _nodes[i]._string;

	delete[] _nodes;

	_nodes = nullptr;

	_size = _capacity = 0;
}

void StringPool::copyFrom(const StringPool & other)
{
	_capacity = other._capacity;
	_size = other._size;

	_nodes = new StringNode[_capacity]{};

	for (int i = 0; i < _size; i++)
	{
		_nodes[i]._string = new char[strlen(other._nodes[i]._string) + 1]{};
		strcpy(_nodes[i]._string, other._nodes[i]._string);
	}
}

void StringPool::resize(size_t newCapacity)
{
	if (newCapacity <= _capacity)
		return;

	StringNode* newNodes = new StringNode[newCapacity]{};

	for (int i = 0; i < _size; i++)
	{
		newNodes[i] = _nodes[i];
	}

	delete[] _nodes;
	_nodes = newNodes;
	_capacity = newCapacity;
}

int StringPool::findString(const char * string, bool & isFound)
{
	int left = 0;
	int right = _size - 1;

	while (left <= right)
	{
		int mid = (right - left) / 2 + left;
		int compare = strcmp(_nodes[mid]._string, string);

		if (compare == 0)
		{
			isFound = true;
			return mid;
		}
		else if (compare > 0)
		{
			right = mid - 1;
		}
		else
		{
			left = mid + 1;
		}
	}

	isFound = false;
	return left;
}

void StringPool::insertString(const char * string, size_t index)
{
	if (index > _size)
		throw std::out_of_range("Invalid index!");

	if(!string)
		throw std::exception("Nullptr");

	if (_size == _capacity)
		resize(roundToPowerOfTwo(_capacity + 1));

	for (int i = _size - 1; i >= (int)index; i--)
	{
		_nodes[i + 1] = _nodes[i];
	}

	_nodes[index].allocateString(string);

	_size++;
}

void StringPool::removeString(const char * string)
{
	if (!string)
		throw std::exception("Nullptr");

	bool isFound = false;
	int index = findString(string, isFound);

	if (isFound)
	{
		delete[] _nodes[index]._string;

		for (int i = index; i < _size; i++)
		{
			_nodes[i] = _nodes[i + 1];
		}

		_nodes[_size - 1]._string = nullptr;

		_size--;
	}
}

StringPool & operator>>(const char * string, StringPool & obj)
{
	obj *= string;

	return obj;
}

std::ostream & operator<<(std::ostream & os, const StringPool & obj)
{
	for (int i = 0; i < obj._size; i++)
	{
		os << obj._nodes[i]._string << ' ';
	}

	os << std::endl;

	return os;
}

StringPool operator+(const StringPool & lhs, const StringPool & rhs)
{
	StringPool sp(lhs);
	sp += rhs;
	return sp;
}

StringPool operator-(const StringPool & lhs, const StringPool & rhs)
{
	StringPool sp(lhs);
	sp -= rhs;
	return sp;
}
