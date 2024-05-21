#include "Question.h"
#include <cstring>
#include <exception>
#pragma warning (disable : 4996)

size_t Question::ask() const
{
	std::cout << "(-) " << _text << std::endl;
	std::cout << "(-) Answers:" << std::endl;
}

Question::Question(const char* text, size_t points) :
	 _points(points)
{
	setText(text);
}

Question::Question(const Question& other)
{
	copyFrom(other);
}

Question& Question::operator=(const Question& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Question::Question(Question&& other) noexcept
{
	moveFrom(std::move(other));
}

Question& Question::operator=(Question&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

void Question::setText(const char* text)
{
	if (!text)
		throw std::exception("Answer::setAnswer - Nullptr");

	delete[] _text;
	_text = new char[strlen(text) + 1] {};

	strcpy(_text, text);
}

Question::~Question()
{
	free();
}

void Question::free()
{
	delete[] _text;
	_text = nullptr;
	_points = 0;
}

void Question::copyFrom(const Question& other)
{
	_points = other._points;
	_text = new char[strlen(other._text) + 1] {};

	strcpy(_text, other._text);
}

void Question::moveFrom(Question&& other)
{
	_points = other._points;
	other._points = 0;

	_text = other._text;
}
