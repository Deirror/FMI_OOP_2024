#include <iostream>
#define MAX_COUNT 30

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

struct GroupStudent
{
	Student students[MAX_COUNT];

	float averageMarkGroup = 0.;

	size_t currCount = 0;

	bool isInitialized = false;

	void initGroup(size_t count)
	{
		if (!isInitialized)
			isInitialized = true;

		if (count > MAX_COUNT)
			return;

		currCount = count;

		for (int i = 0; i < count; i++)
		{
			students[i] = initStudent();
		}

		averageMarkGroup = calculateAverageMark();
	}

	size_t calculateAverageMark()
	{
		float result = 0.;

		for (int i = 0; i < currCount; i++)
		{
			result += students[i].averageMark;
		}

		return result / currCount;
	}

	size_t getStudentsWithScholarship(float minAverageMark)
	{
		size_t result = 0;

		for (int i = 0; i < currCount; i++)
		{
			if (students[i].averageMark >= minAverageMark)
				result++;
		}

		return result;
	}
};

void printSortedGroupDescending(const GroupStudent& obj, float minAverageMark)
{
	GroupStudent result = obj;

	for (int i = 0; i < result.currCount - 1; i++)
	{
		for (int j = i; j < result.currCount; j++)
		{
			if (result.students[j].averageMark < result.students[j + 1].averageMark)
			{
				std::swap(result.students[j], result.students[j + 1]);
			}
		}
	}

	for (int i = 0; i < result.currCount - 1; i++)
	{
		if (result.students[i].averageMark >= minAverageMark)
		{
			result.students[i].printStudent();
		}
		else
		{
			break;
		}
	}
}

int main()
{
	GroupStudent group;

	group.initGroup(3);

	std::cout << group.getStudentsWithScholarship(2.50);

	printSortedGroupDescending(group, 3.0);
	
	return 0;
}
