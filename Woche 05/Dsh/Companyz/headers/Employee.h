#pragma once
#include <cstring>
#include "Errors.h"
#define MAX_LEN 128
#pragma warning (disable : 4996)

class Employee
{
private:
	unsigned id = 0;

	char name[MAX_LEN]{};

	char position[MAX_LEN]{};

	double salary = 0.;

public:
	Employee() = default;

	Employee(unsigned _id, const char* _name, const char* _position, double _salary);

	ErrorCode updateSalary(double amount);

	void setName(const char* _name);

	void setPosition(const char* _position);

	void setSalary(double _salary);

	unsigned getId() const;

	const char* getName() const;

	const char* getPosition() const;

	double getSalary() const;
};

