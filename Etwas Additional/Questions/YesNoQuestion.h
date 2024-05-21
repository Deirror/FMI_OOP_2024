#pragma once
#include "Question.h"

class YesNoQuestion : Question
{
private:
	Answer _answers[2] = { {"Yes", false}, {"No", false}};
	size_t grade(size_t answer) const override;

public:
	YesNoQuestion() = delete;
	YesNoQuestion(const char* text, size_t points, char yesOrNo);

	size_t ask() const override;
	virtual Question* clone() const override;

};

