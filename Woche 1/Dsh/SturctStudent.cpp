#include <iostream>

struct Student
{
	size_t fn = 0;
	short course = 0;
	float averageMark = 0.;

	void printStudent()
	{
		std::cout << "FN : " << fn << std::endl;

		std::cout << "Course : " << course << std::endl;

		std::cout << "Average Mark : " << averageMark << std::endl;
	}

	bool isFnValid()
	{
		constexpr short VALID_LEN = 5;

		size_t copiedFn = fn;

		size_t counter = 1;

		while (copiedFn != 0 && counter++)
		{
			copiedFn = (copiedFn / 10);
		}

		return (--counter == VALID_LEN);
	}

	bool isCourseValid()
	{
		return course > 0 && course < 5;
	}

	bool isAverageMarkValid()
	{
		return averageMark >= 2.0 && averageMark <= 6.0;
	}
};

Student initStudent()
{
	Student student;

	std::cout << '>';
	std::cin >> student.fn;

	if (!student.isFnValid())
		return {};

	std::cout << '>';
	std::cin >> student.course;

	if (!student.isCourseValid())
		return {};

	std::cout << '>';
	std::cin >> student.averageMark;

	if (!student.isAverageMarkValid())
		return {};

	return student;
}

int main()
{
	Student student;

	student = initStudent();

	student.printStudent();

	return 0;
}