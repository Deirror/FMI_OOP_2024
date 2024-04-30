#include <iostream>
#include <fstream>
#define FILENAME "r.txt"

int maxIndex(const int* arr, int size)
{
	int maxIndex = 0;

	for (int i = 1; i < size; i++)
	{
		if (arr[maxIndex] < arr[i])
			maxIndex = i;
	}


    return maxIndex;
}

void mostCommonNumberInFile()
{
	std::ifstream ifs(FILENAME);

	if (!ifs.is_open())
		return;

	int size = 0;

	ifs >> size;

	if (size > 64)
		return;

	int* arr = new int[size];

	for (int i = 0; i < size; i++)
	{
		ifs >> arr[i];
	}

	ifs.close();

	int histSize = arr[maxIndex(arr, size)] + 1;

	int* histogram = new int[histSize]{};

	for (int i = 0; i < size; i++)
	{
		histogram[arr[i]]++;
	}

	std::cout << maxIndex(histogram, histSize);

	delete[] histogram;
	delete[] arr;
}

int main()
{
	mostCommonNumberInFile();

	return 0;
}