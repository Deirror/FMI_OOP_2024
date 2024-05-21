#include "YesNoQuestion.h"

YesNoQuestion::YesNoQuestion(const char* text, size_t points, char yesOrNo) : Question(text, points)
{
	hasCorrectAnswer = true;

	switch (yesOrNo)
	{
	case 'y':
	{
		_answers[0].setIsCorrect(true);
	}
	case 'n':
	{
		_answers[1].setIsCorrect(true);
	}
	default:
	{
		hasCorrectAnswer = false;
		break;
	}
	}
}

size_t YesNoQuestion::ask() const
{
	Question::ask();

	std::cout << "1." << _answers[0].getAnswer() << std::endl;
	std::cout << "2." << _answers[1].getAnswer() << std::endl;

	unsigned answer = 0;
	std::cin >> answer;
	
	if(answer >= 1 && answer <=2)
	    return grade(answer - 1);

	return 0;
}

Question* YesNoQuestion::clone() const
{
	return new YesNoQuestion(*this);
}

size_t YesNoQuestion::grade(size_t answer) const
{
	if (!hasCorrectAnswer)
		return 0;

	if (_answers[answer].getIsCorrect())
	{
		return _points;
	}

	return 0;
}
