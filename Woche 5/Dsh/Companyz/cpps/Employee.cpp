#include "Employee.h"

Employee::Employee(unsigned _id, const char * _name, const char * _position, double _salary) : id(_id)
{
	setName(_name);

	setPosition(_position);

	setSalary(_salary);
}

double Employee::getSalary() const
{
	return salary;
}

ErrorCode Employee::updateSalary(double amount)
{
	if (salary - amount < 0.)
		return ErrorCode::InvalidInput;

	salary += amount;

	return ErrorCode::OK;
}

void Employee::setName(const char * _name)
{
	if (!_name)
		return;

	strcpy(name, _name);
}

void Employee::setPosition(const char * _position)
{
	if (!_position)
		return;

	strcpy(position, _position);
}

void Employee::setSalary(double _salary)
{
	if (_salary < 0.)
		return;

	salary = _salary;
}

unsigned Employee::getId() const
{
	return id;
}

const char * Employee::getName() const
{
	return name;
}

const char * Employee::getPosition() const
{
	return position;
}
