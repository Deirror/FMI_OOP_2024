#include <iostream>
#define MAX_LEN 50
#define MAX_COUNT 5
#define ANSWERS 4

enum class Answer
{
	A,
	B,
	C,
	D,
	Other
};

struct Question
{
	char answers[ANSWERS][MAX_LEN]{};

	char title[MAX_LEN]{};

	Answer correctAnswer = Answer::Other;

	size_t points = 0;

	void printQuestion()
	{
		std::cout << "(-)" << title << "?\n";

		for (int i = 0; i < ANSWERS; i++)
		{
			std::cout << (char)(i + 'A') << '.' << answers[i] << std::endl;
		}
	}

};

struct Test
{
	Question questions[MAX_COUNT];

	size_t currCount = 0;

	size_t gainedPoint = 0;

	void addQuestion(const Question& obj)
	{
		if (currCount == MAX_COUNT)
			return;

		questions[currCount++] = obj;
	}
};

void runTest(Test& test)
{
	char answer;

	for (int i = 0; i < test.currCount; i++)
	{
		test.questions[i].printQuestion();

		std::cout << '>';
		std::cin >> answer;

		switch (test.questions[i].correctAnswer)
		{
		case Answer::A:
		{
			if (answer == 'A')
				test.gainedPoint += test.questions[i].points;

			break;
		}
		case Answer::B:
		{
			if (answer == 'B')
				test.gainedPoint += test.questions[i].points;

			break;
		}
		case Answer::C:
		{
			if (answer == 'C')
				test.gainedPoint += test.questions[i].points;

			break;
		}
		case Answer::D:
		{
			if (answer == 'D')
				test.gainedPoint += test.questions[i].points;

			break;
		}
		default:
			std::cout << "wtf...\n";
		}
	}
}

int main()
{
	Question q1 = { {"Sofia","Ivanoskow","Solun","Zarigrad"}, "What is the capital of Old Disciplinia?", Answer::B, 20 };
	Question q2 = { {"Kyroan","Riebenport","Berlein","Kanzstadt"}, "What is the capital of Deirroren Kanzlernd?", Answer::A, 40 };

	Test test;

	test.addQuestion(q1);
	test.addQuestion(q2);

	runTest(test);

	std::cout << test.gainedPoint;

	return 0;
}