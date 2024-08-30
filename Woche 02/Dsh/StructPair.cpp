#include <iostream>
#include <fstream>
#define MAX_COUNT 25

struct Pair
{
	int firstEl = 0;
	int secondEl = 0;
};

Pair initPair()
{
	Pair result;

	std::cin >> result.firstEl >> result.secondEl;

	return result;
}

struct RelationPair
{
	Pair pairs[MAX_COUNT];

	size_t currCount = 0;

	void addPair()
	{
		if (currCount == MAX_COUNT)
			return;

		pairs[currCount++] = initPair();
	}

	void readPairs(const char* fileName)
	{
		if (!fileName)
			return;

		std::ifstream ifs(fileName);

		if (!ifs.is_open())
			return;
		//(1,2),(3,4)
		while (!ifs.eof())
		{
			ifs.ignore();//(
			ifs >> pairs[currCount].firstEl;
			ifs.ignore();//,
			ifs >> pairs[currCount++].secondEl;
			ifs.ignore();//)
			ifs.ignore();//,

			if (currCount == MAX_COUNT)
			{
				ifs.close();
				return;
			}
		}

		ifs.close();
	}

	void savePairs(const char* fileName)
	{
		if (!fileName)
			return;

		std::ofstream ofs(fileName);

		if (!ofs.is_open())
			return;

		for (int i = 0; i < currCount; i++)
		{
			ofs << '(' << pairs[i].firstEl << ',' << pairs[i].secondEl << ')';

			if (i != currCount - 1)
				ofs << ',';
		}

		ofs.close();
	}
};

int main()
{
	RelationPair rp;

	rp.addPair();

	rp.readPairs("r.txt");

	rp.savePairs("s.txt");

	return 0;
}