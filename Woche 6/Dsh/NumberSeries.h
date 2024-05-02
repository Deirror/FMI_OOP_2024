#pragma once
#include <climits>
#define DEFAULT_CAPACITY 8
#define LIMIT SHRT_MAX
using FuncPtr = int (*) (int);

class NumberSeries
{
private:
	int a0 = 0;
	
	FuncPtr func = nullptr;

	int* numSeriesArray = nullptr;

	size_t currSize = 0;

public:
	NumberSeries() = delete;
	NumberSeries(int _a0, FuncPtr _func);

	NumberSeries(const NumberSeries& other);
	NumberSeries& operator=(const NumberSeries& other);

	~NumberSeries();

	int generateINumber(int i);

	bool isNumberFromSeries(int number, int startingIndex = 0);

	void setA0(int newA0);

	void setFunc(FuncPtr _func);

private:
	void free();

	void copyFrom(const NumberSeries& other);

	void calculateNextNumbers();

	void resize(int index);
};

