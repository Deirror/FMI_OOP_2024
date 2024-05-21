#include "Test.h"

Test::Test() : _size(0), _capacity(DEF_CAP)
{
	_questions = new Question * [_capacity];
}

Test::Test(const Test& other)
{
	copyFrom(other);
}

Test& Test::operator=(const Test& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Test::Test(Test&& other) noexcept
{
	moveFrom(std::move(other));
}

Test& Test::operator=(Test&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Test::~Test()
{
	free();
}

void Test::free()
{
	for (int i = 0; i < _size; i++)
	{
		delete _questions[i];
	}

	delete[] _questions;
	_questions = nullptr;

	_size = 0;
	_capacity = DEF_CAP;
}

void Test::copyFrom(const Test& other)
{
	_size = other._size;
	_capacity = other._capacity;

	_questions = new Question * [_capacity];

	for (int i = 0; i < _size; i++)
	{
		_questions[i] = other._questions[i]->clone();
	}
}

void Test::moveFrom(Test&& other)
{
	_size = other._size;
	_capacity = other._capacity;

	other._size = other._capacity = 0;

	_questions = other._questions;
	other._questions = nullptr;

	_pointsFromTest = other._pointsFromTest;
}

void Test::resize(size_t newCapacity)
{
	Question** newQuestions = new Question * [newCapacity];

	for (int i = 0; i < _size; i++)
	{
		newQuestions[i] = _questions[i];
	}

	delete[] _questions;

	_questions = newQuestions;

	_capacity = newCapacity;
}
