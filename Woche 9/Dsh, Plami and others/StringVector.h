#pragma once
#include "String.h"


class StringVector
{
private:
	String* _strings = nullptr;

	size_t _size = 0;

	size_t _capacity = 0;

public:
	StringVector();

	StringVector(const StringVector& other);
	StringVector& operator=(const StringVector& other);

	StringVector(StringVector&& other) noexcept;
	StringVector& operator=(StringVector&& other) noexcept;

	~StringVector();

	void push_back(const String& other);
	void pop_back();

	void insert(const String& string, size_t index);
	void erase(size_t index);

	void push_back(String&& other);
	void insert(String&& other, size_t index);

	void clear();

	String& operator[](size_t index);
	const String& operator[](size_t index) const;

	bool empty();
	size_t getSize() const;

	void debug() const;

private:
	void free();
	void copyFrom(const StringVector& other);

	void moveFrom(StringVector&& other);

	void resize(size_t newCapacity);
};

