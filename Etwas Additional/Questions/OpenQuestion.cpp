#include "OpenQuestion.h"

OpenQuestion::OpenQuestion(const char* text, size_t points) :  Question(text,points)
{
}

size_t OpenQuestion::ask() const
{
	Question::ask();

	std::cout << '>';

	char buff[100]{};

	std::cin.getline(buff, 100);

	std::cout << ">Now grading...\n";

	if (!strlen(buff))
	{
		std::cout << ">oopss, no answer, no points\n";
		return 0;
	}

	unsigned procents = 0;
	std::cin >> procents;

	return grade(procents/100);
}

Question* OpenQuestion::clone() const
{
	return new OpenQuestion(*this);
}

size_t OpenQuestion::grade(size_t answer) const
{
	return _points * answer;
}
