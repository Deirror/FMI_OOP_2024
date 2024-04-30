#include <iostream>
#include <fstream>
#define MAX_LEN 64
#define MAX_COUNT 20
#pragma warning (disable : 4996)


struct City
{
	char name[MAX_LEN]{};

	size_t population = 0;
};

struct District
{
	City cities[MAX_COUNT];

	size_t currCount = 0;

	void saveDistrict(const char* fileName)
	{
		if (!fileName)
			return;

		std::ofstream ofs(fileName);

		if (!ofs.is_open())
			return;

		for (int i = 0; i < currCount; i++)
		{
			ofs << cities[i].name << '|' << cities[i].population;

			if (i != currCount - 1)
				ofs << ' ';
		}

		ofs.close();

	}

	void sortDistrictByPopulation()
	{
		for (int i = 0; i < currCount - 1; i++)
		{
			for (int j = 0; j < currCount - 1; j++)
			{
				if (cities[j].population > cities[j + 1].population)
					std::swap(cities[j], cities[j+1]);
			}
		}
	}
};

void saveSortedReadDistrict(const char* readFileName, const char* writeFileName)
{
	if (!readFileName || !writeFileName)
		return;

	District toReadDistrict;

	std::ifstream ifs(readFileName);

	if (!ifs.is_open())
		return;

	char buffName[100]{};

	while (!ifs.eof())
	{
		ifs.getline(buffName, 100, '|');

		strcpy(toReadDistrict.cities[toReadDistrict.currCount].name, buffName);

		ifs >> toReadDistrict.cities[toReadDistrict.currCount++].population;

		ifs.ignore();//' '

		if (toReadDistrict.currCount == MAX_COUNT)
			break;
	}

	ifs.close();

	toReadDistrict.sortDistrictByPopulation();

	toReadDistrict.saveDistrict(writeFileName);
}

int main()
{
	saveSortedReadDistrict("rd.txt","tw.txt");


	return 0;
}