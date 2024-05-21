#pragma once
#include "Question.h"
#define DEF_CAP 8

class Test
{
private:
	Question** _questions = nullptr;
	size_t _size = 0;

	size_t _capacity = 0;

	mutable size_t _pointsFromTest = 0;

public:
	Test();

	Test(const Test& other);
	Test& operator=(const Test& other);

	Test(Test&& other) noexcept;
	Test& operator=(Test&& other) noexcept;

	~Test();

	void addQuestion(const Question* obj);

	void doTest() const;

private:
	void free();
	void copyFrom(const Test& other);
	void moveFrom(Test&& other);

	void resize(size_t newCapacity);

	void gradeTest() const;
};

