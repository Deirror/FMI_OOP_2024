#include "Student.h"

Student::Student(const String & name, unsigned fn, unsigned course)
{
	setName(name);
	setFn(fn);
	setCourse(course);
}

void Student::setName(const String & name)
{
	if (!strlen(name.c_string()))
		throw std::exception("Empty name");

	_name = name;
}

void Student::setFn(unsigned fn)
{
	if (strlen((const char*)fn) != LEN_FN)
		throw std::exception("Not in correct format");

	_fn = fn;
}

void Student::setCourse(unsigned course)
{
	if(course < MIN_CRS || course > MAX_CRS)
		throw std::exception("Not in correct format");

	_course = course;
}

const String & Student::getName() const
{
	return _name;
}

unsigned Student::getFn() const
{
	return _fn;
}

unsigned Student::getCourse() const
{
	return _course;
}

