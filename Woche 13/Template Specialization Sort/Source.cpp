#include <iostream>

template <typename T>
void sortArray(T* arr, size_t size)
{
	if (!arr)
		return;

	int i, key, j = 0;
	for (i = 1; i < size; i++)
	{
		key = arr[i];
		j = i - 1;

		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
}

template<>
void sortArray(char* arr, size_t size)
{
	if (!arr)
		return;

	char max = '\0';

	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
			max = arr[i];

	}

	int histSize = max + 1;
	unsigned short* histogram = new unsigned short[histSize] {};

	for (int i = 0; i < size; i++)
	{
		histogram[arr[i]]++;
	}

	int times = 0;
	int arrIndex = 0;

	for (int i = 0; i < histSize; i++)
	{
		times = histogram[i];

		for (int j = 0; j < times; j++)
		{
			arr[arrIndex++] = i;
		}
	}

	delete[] histogram;
}

int main()
{
	char arr[] = "olleH";

	sortArray(arr, 5);

	int ar1[] = { 2,3,5,3 };

	sortArray(ar1, 4);

	return 0;
}