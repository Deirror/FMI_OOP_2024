#include <iostream>
#define MAX_LEN 101
#define MAX_COUNT 69

enum class Position
{
	Other,
	SoftwareEngineer,
	SeniorSoftwareEngineer,
	EngineerManager, 
	LeadSoftwareEngineer
};

struct EmployeeIT
{
	double salary = 0.;
	
	Position position = Position::Other;

	char name[MAX_LEN]{};

	int rating = 0;

	void print()
	{
		std::cout << name << std::endl;

		std::cout << salary << std::endl;

		std::cout << rating << std::endl;

		switch (position)
		{
		case Position::SoftwareEngineer:
			std::cout << "SoftwareEngineer\n";
			break;
		case Position::SeniorSoftwareEngineer:
			std::cout << "SeniorSoftwareEngineer\n";
			break;
		case Position::EngineerManager:
			std::cout << "EngineerManager\n";
			break;
		case Position::LeadSoftwareEngineer:
			std::cout << "LeadSoftwareEngineer\n";
			break;
		default:
			std::cout << "Nothing :(( \n";
			break;
		}
	}
};

EmployeeIT initEmployee()
{
	EmployeeIT result;

	std::cout << '>';
	std::cin.getline(result.name, MAX_LEN);

	std::cout << '>';
	std::cin >> result.salary;

	std::cout << '>';
	std::cin >> result.rating;

	int rating = 0;
	std::cout << '>';
	std::cin >> rating;
	
	switch (rating)
	{
	case 1:
	{
		result.position = Position::SoftwareEngineer;
		break;
	}
	case 2:
	{
		result.position = Position::EngineerManager;
		break;
	}
	case 3:
	{
		result.position = Position::SeniorSoftwareEngineer;
		break;
	}
	case 4:
	{
		result.position = Position::LeadSoftwareEngineer;
		break;
	}
	}

	return result;
}

struct Company
{
	EmployeeIT employees[MAX_COUNT];

	size_t currCount = 0;

	bool isInitialized = false;

	void initCompany(size_t count)
	{
		if (!isInitialized)
			isInitialized = true;

		currCount = count;

		for (int i = 0; i < count; i++)
		{
			employees[i] = initEmployee();
		}
	}

	void printMaxAndMinRatings()
	{
		int max = 0;
		int min = 0;

		for (int i = 1; i < currCount; i++)
		{
			if (employees[min].rating > employees[i].rating)
				min = i;

			if (employees[max].rating < employees[i].rating)
				max = i;
		}

		std::cout << employees[min].rating << std::endl;
		std::cout << employees[max].rating << std::endl;
	}

	void printRicherEmployees(double minSalary)
	{
		Company result = *this;

		for (int i = 0; i < result.currCount - 1; i++)
		{
			for (int j = i; j < result.currCount - 1; j++)
			{
				if (result.employees[j].salary < result.employees[j + 1].salary)
					std::swap(result.employees[j], result.employees[j + 1]);
			}
		}

		for (int i = 0; i < result.currCount; i++)
		{
			if (result.employees[i].salary >= minSalary)
			{
				std::cout << result.employees[i].name;
			}
			else
			{
				break;
			}
		}
	}
};



int main()
{

	return 0;
}