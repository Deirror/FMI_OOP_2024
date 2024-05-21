#include "Answer.h"
#include <cstring>
#include <exception>
#pragma warning (disable : 4996)

Answer::Answer(const char* answer, const bool* const isCorrect)
{
	setAnswer(answer);
	setIsCorrect(isCorrect);
}

Answer::Answer(const Answer& other)
{
	copyFrom(other);
}

Answer& Answer::operator=(const Answer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Answer::Answer(Answer&& other) noexcept
{
	moveFrom(std::move(other));
}

Answer& Answer::operator=(Answer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Answer::~Answer()
{
	free();
}

void Answer::setAnswer(const char* answer)
{
	if (!answer)
		throw std::exception("Answer::setAnswer - Nullptr");

	delete[] _answer;
	_answer = new char[strlen(answer) + 1] {};

	strcpy(_answer, answer);
}

void Answer::setIsCorrect(bool isCorrect)
{
	_isCorrect = isCorrect;
}

const char* Answer::getAnswer() const
{
	return _answer;
}

bool Answer::getIsCorrect() const
{
	return _isCorrect;
}

void Answer::free()
{
	delete[] _answer;
	_answer = nullptr;

	_isCorrect = false;
}

void Answer::copyFrom(const Answer& other)
{
	_answer = new char[strlen(other._answer) + 1] {};

	strcpy(_answer, other._answer);

	setIsCorrect(other._isCorrect);
}

void Answer::moveFrom(Answer&& other)
{
	_answer = other._answer;
	other._answer = nullptr;

	_isCorrect = other._isCorrect;
}
