#include "Department.h"

Department::Department(const char * _name, const Employee * _employees, unsigned count) : countOfEmployees(count)
{
	setName(_name);

	if (_employees)
	{
		for (int i = 0; i < count; i++)
		{
			employees[i] = _employees[i];
		}
	}	
}

void Department::setName(const char * _name)
{
	if (!_name)
		return;

	strcpy(name, _name);
}

const char * Department::getName() const
{
	return name;
}

const Employee * Department::getEmployees() const
{
	return employees;
}

ErrorCode Department::addEmployee(const Employee & employee)
{
	if (countOfEmployees == MAX_COUNT)
		return ErrorCode::Full;

	employees[countOfEmployees++] = employee;

	return ErrorCode::OK;
}

ErrorCode Department::removeEmployee(unsigned id)
{
	if (countOfEmployees == 0)
		return ErrorCode::Empty;

	size_t countOfId = 0;

	size_t index = -1;

	for (int i = 0; i < countOfEmployees; i++)
	{
		if (employees[i].getId() == id)
		{
			index = i;
			countOfId++;
		}
	}

	if (countOfId >= 2)
		return ErrorCode::Duplicate;

	if (index == -1)
		return ErrorCode::NotFound;

	for (int i = index; i < countOfEmployees - 1; i++)
	{
		employees[i] = employees[i + 1];
	}

	countOfEmployees--;

	return ErrorCode::OK;
}
