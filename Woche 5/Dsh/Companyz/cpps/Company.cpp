#include "Company.h"

ErrorCode Company::addDepartment(const char * name)
{
	if (!name)
		return ErrorCode::InvalidInput;

	if (countOfDepartments == MAX_COUNT)
		return ErrorCode::Full;

	departments[countOfDepartments++].setName(name);

	return ErrorCode::OK;
}

ErrorCode Company::removeDepartment(const char * name)
{
	if (!name)
		return ErrorCode::InvalidInput;

	if (countOfDepartments == 0)
		return ErrorCode::Empty;

	int index = -1;

	for (int i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), name) == 0)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		return ErrorCode::NotFound;

	for (int i = index; i < countOfDepartments - 1; i++)
	{
		departments[i] = departments[i + 1];
	}

	countOfDepartments--;

	return ErrorCode::OK;
}

ErrorCode Company::addEmployeeToDepartment(const char * departmentName, const Employee & employee)
{
	if (!departmentName)
		return ErrorCode::InvalidInput;

	int index = -1;

	for (int i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		return ErrorCode::NotFound;

	departments[index].addEmployee(employee);

	return ErrorCode::OK;
}

ErrorCode Company::removeEmployeeFromDepartment(const char * departmentName, unsigned id)
{
	if (!departmentName)
		return ErrorCode::InvalidInput;

	int index = -1;

	for (int i = 0; i < countOfDepartments; i++)
	{
		if (strcmp(departments[i].getName(), departmentName) == 0)
		{
			index = i;
			break;
		}
	}

	if (index == -1)
		return ErrorCode::NotFound;

	ErrorCode ec = departments[index].removeEmployee(id);

	if (ec != ErrorCode::OK)
		return ec;

	return ErrorCode::OK;
}
