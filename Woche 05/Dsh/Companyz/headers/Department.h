#pragma once
#include <cstring>
#include "Employee.h"
#include "Errors.h"
#define MAX_LEN 128
#define MAX_COUNT 15

class Department
{
private:
	char name[MAX_LEN]{};

	Employee employees[MAX_COUNT];

	unsigned countOfEmployees = 0;
public:
	Department() = default;

	Department(const char* _name, const Employee* _employees, unsigned count);

	void setName(const char* _name);

	const char* getName() const;

	const Employee* getEmployees() const;

	ErrorCode addEmployee(const Employee& employee);

	ErrorCode removeEmployee(unsigned id);
};

