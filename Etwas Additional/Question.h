#pragma once
#include <iostream>
#include "Answer.h"

class Question
{
protected:
	char* _text = nullptr;

	size_t _points = 0;

	//Some Questions don't have correct or incorrect answer. There are open-questioned
	mutable bool hasCorrectAnswer = true;
	virtual size_t grade(size_t answer) const = 0;

public:
	Question() = delete;

	Question(const char* text, size_t points);

	Question(const Question& other);
	Question& operator=(const Question& other);

	Question(Question&& other) noexcept;
	Question& operator=(Question&& other) noexcept;

	void setText(const char* text);

	virtual size_t ask() const = 0;

	virtual Question* clone() const = 0;

	virtual ~Question();

private:
	void free();
	void copyFrom(const Question& other);
	void moveFrom(Question&& other);


};

