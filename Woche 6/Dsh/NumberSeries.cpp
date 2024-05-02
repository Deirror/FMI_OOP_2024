#include "NumberSeries.h"

unsigned roundToPowerOfTwo(int index)
{
	short times = 3;

	while (index - (1 << times++) >= 0);

	return (1 << --times);
}

NumberSeries::NumberSeries(int _a0, FuncPtr _func) : a0(_a0), func(_func)
{
	currSize = DEFAULT_CAPACITY;

	numSeriesArray = new int[currSize];

	calculateNextNumbers();
}

NumberSeries::NumberSeries(const NumberSeries & other)
{
	copyFrom(other);
}

NumberSeries & NumberSeries::operator=(const NumberSeries & other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

NumberSeries::~NumberSeries()
{
	delete[] numSeriesArray;
}

int NumberSeries::generateINumber(int i) 
{
	if (i >= currSize)
	{
		resize(i);

		calculateNextNumbers();
	}

	return numSeriesArray[i];;
}

bool NumberSeries::isNumberFromSeries(int number, int startingIndex)
{
	bool flag = false;

	for (int& i = startingIndex; i < currSize; i++)
	{
		if (number == numSeriesArray[i])
		{
			flag = true;
			return flag;
		}
	}

	if (!flag)
	{
		resize(currSize + 1);

		calculateNextNumbers();

		if (currSize >= LIMIT)
			return false;

		isNumberFromSeries(number, startingIndex);
	}

}

void NumberSeries::setA0(int newA0)
{
	a0 = newA0;

	calculateNextNumbers();
}

void NumberSeries::setFunc(FuncPtr _func)
{
	func = _func;

	calculateNextNumbers();
}

void NumberSeries::free()
{
	delete[] numSeriesArray;

	numSeriesArray = nullptr;

	a0 = 0;

	func = nullptr;

	currSize = 0;
}

void NumberSeries::copyFrom(const NumberSeries & other)
{
	a0 = other.a0;
	func = other.func;

	currSize = other.currSize;

	numSeriesArray = new int[currSize] {};

	for (int i = 0; i < currSize; i++)
	{
		numSeriesArray[i] = other.numSeriesArray[i];
	}
}

void NumberSeries::calculateNextNumbers()
{
	numSeriesArray[0] = a0;

	for (int i = 1; i < currSize; i++)
	{
		numSeriesArray[i] = func(numSeriesArray[i - 1]);
	}
}

void NumberSeries::resize(int index)
{
	currSize = roundToPowerOfTwo(index);

	delete[] numSeriesArray;

	numSeriesArray = new int[currSize];
}
