#include <iostream>
#include <fstream>
#define MAX_LEN 65
#pragma warning (disable : 4996)

size_t getCountOfSymbolInFile(std::ifstream& ifs, char specialSymbol)
{
	size_t result = 0;
	char symbol;

	while (true)
	{
		ifs.get(symbol);

		if (specialSymbol == symbol)
			result++;

		if (ifs.eof())
			break;
	}

	ifs.clear();
	ifs.seekg(0);

	return result;
}

void free(char** placeHolders, char** values, int size)
{
	for (int i = 0; i < size; i++)
	{
		delete placeHolders[i];
		delete values[i];
	}

	delete[] placeHolders;
	delete[] values;
}

void initPointers(char** placeHolders, char** values, int size)
{
	for (int i = 0; i < size; i++)
	{
		placeHolders[i] = new char[MAX_LEN] {};
		values[i] = new char[MAX_LEN] {};
	}
}

bool myStrcmp(const char* fromFile, const char* value)
{
	if (!fromFile || !value)
		return false;

	while (*value && *fromFile)
	{
		if (*fromFile++ != *value++)
			break;
	}

	return !*value && !*fromFile;
}

void fillInPlaceHolders(const char* shablonName, const char* sourceName, const char* finalName)
{
	if (!shablonName || !sourceName || !finalName)
		return;

	std::ifstream ifs(sourceName);

	if (!ifs.is_open())
		return;

	int size = getCountOfSymbolInFile(ifs, '\n') + 1;

	char** placeHolders = new char*[size]{};

	char** values = new char*[size]{};

	initPointers(placeHolders, values, size);

	int index = 0;

	char buff[MAX_LEN]{};

	while (!ifs.eof())
	{
		ifs >> buff;
		strcpy(placeHolders[index], buff);

		ifs.getline(buff,MAX_LEN);
		strcpy(values[index++], buff);
	}

	ifs.close();

	ifs.open(shablonName);

	if (!ifs.is_open())
		return;

	std::ofstream ofs(finalName);

	if (!ofs.is_open())
		return;

	char symbol;

	while(true)
	{
		ifs.get(symbol);

		if (symbol == '{')
		{
			ifs.getline(buff, MAX_LEN, '}');

			for (int i = 0; i < size; i++)
			{
				if (myStrcmp(buff, placeHolders[i]))
				{
					ofs << values[i];
					break;
				}
			}
		}
		else
		{
			ofs << symbol;
		}

		if (ifs.eof())
			break;
	}

	ifs.close();
	ofs.close();

	free(placeHolders, values, size);
}

int main()
{
	fillInPlaceHolders("shablon.txt", "values.txt", "res.txt");

	return 0;
}