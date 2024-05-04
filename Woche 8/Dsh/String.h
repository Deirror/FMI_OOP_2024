#pragma once
#include <iostream>
#define DEFUALT_CAPACITY 8

class String
{
private:
	char* _string = nullptr;

	size_t _length = 0;
	size_t _capacity = 0;

public:
	String();
	String(const char* string);

	String(const String& other);
	String& operator=(const String& other);

    ~String();

	String& operator+=(const String& other);


	const char* c_string() const;
	size_t getCapacity() const;
	size_t getLength() const;

	char& operator[](size_t index);
	const char& operator[](size_t index) const;

	friend std::ostream& operator<<(std::ostream& os, const String& obj);
	friend std::istream& operator>>(std::istream& is, String& ref);
	friend String operator+(const String& lhs, const String& rhs);

	void debug() const;

private:
	void free();
	void copyFrom(const String& other);

	void resize(size_t stringSize);

	explicit String(size_t stringLength);
};

bool operator==(const String& lhs, const String& rhs);
bool operator!=(const String& lhs, const String& rhs);
bool operator<(const String& lhs, const String& rhs);
bool operator<=(const String& lhs, const String& rhs);
bool operator>(const String& lhs, const String& rhs);
bool operator>=(const String& lhs, const String& rhs);