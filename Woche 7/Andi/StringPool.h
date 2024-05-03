#pragma once
#include <iostream>
#define DEFAULT_CAPACITY 8

class StringPool
{
private:
	struct StringNode
	{
		char* _string = nullptr;

		void allocateString(const char* string);
	};

	StringNode* _nodes = nullptr;

	size_t _size = 0;
	size_t _capacity = 0;

public:
	StringPool();

	StringPool(const StringPool& other);
	StringPool& operator=(const StringPool& other);

	~StringPool();

	StringPool& operator+=(const StringPool& other);
	StringPool& operator-=(const StringPool& other);
	StringPool& operator*=(const char* string);
	StringPool& operator/=(const char* string);

	bool operator[](const char* string);

	friend StringPool& operator>>(const char* string, StringPool& obj);
	friend std::ostream& operator<<(std::ostream& os, const StringPool& obj);

private:
	void free();

	void copyFrom(const StringPool& other);

	void resize(size_t newCapacity);

	int findString(const char* string, bool& isFound);
	void insertString(const char* string, size_t index);
	void removeString(const char* string);

};

StringPool operator+(const StringPool& lhs, const StringPool& rhs);
StringPool operator-(const StringPool& lhs, const StringPool& rhs);

