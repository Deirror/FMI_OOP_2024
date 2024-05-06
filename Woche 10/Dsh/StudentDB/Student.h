#pragma once
#include "String.h"

class Student
{
public:
	static constexpr short LEN_FN = 5;
	static constexpr short MIN_CRS = 1;
	static constexpr short MAX_CRS = 4;

private:
	String _name;
	unsigned _fn = 0;
	unsigned _course = 0;

public:
	Student() = default;
	Student(const String& name, unsigned fn, unsigned course);

	void setName(const String& name);
	void setFn(unsigned fn);
	void setCourse(unsigned course);

	const String& getName() const;
	unsigned getFn() const;
	unsigned getCourse() const;
};

