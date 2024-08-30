#pragma once
#include "Errors.h"
#include "Department.h"
#define MAX_COUNT 10

class Company
{
private:
	Department departments[MAX_COUNT];

	unsigned countOfDepartments = 0;

public:
	Company() = default;

	ErrorCode addDepartment(const char* name);

	ErrorCode removeDepartment(const char* name);

	ErrorCode addEmployeeToDepartment(const char* departmentName, const Employee& employee);

	ErrorCode removeEmployeeFromDepartment(const char* departmentName, unsigned id);
};

