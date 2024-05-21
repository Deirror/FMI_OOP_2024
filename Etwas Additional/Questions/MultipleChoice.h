#pragma once
#include "Question.h"

class MultipleChoice : Question
{
private:
	Answer* _answers = nullptr;

	size_t _count = 0;

public:
	MultipleChoice() = delete;

	MultipleChoice(const char* _text, size_t _points, const Answer* answers, size_t count, const bool* correctAnswers);

	MultipleChoice(const MultipleChoice& other);
	MultipleChoice& operator=(const MultipleChoice& other);

	MultipleChoice(MultipleChoice&& other) noexcept;
	MultipleChoice& operator=(MultipleChoice&& other) noexcept;

	~MultipleChoice();

	void setAnswers(const Answer* answers, size_t count, const bool* correctAnswers);

	virtual size_t ask() const override;

	virtual Question* clone() const override;

private:
	void free();
	void copyFrom(const MultipleChoice& other);
	void moveFrom(MultipleChoice&& other);

	virtual size_t grade(size_t answer) const override;
};

