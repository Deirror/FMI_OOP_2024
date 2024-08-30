#include <iostream>
#include <fstream>
#include <cstring>
#define FFILENAME "f.txt"
#define SFILENAME "s.txt"

void compareContentFiles(const char* file1, const char* file2)
{
	if (!file1 || !file2)
		return;

	std::ifstream ifs1(file1);

	if (!ifs1.is_open())
		return;

	std::ifstream ifs2(file2);

	if (!ifs2.is_open())
		return;

	char buff1[1024]{};
	char buff2[1024]{};

	while (!ifs1.eof() && !ifs2.eof())
	{
		ifs1.getline(buff1, 1024);
		ifs2.getline(buff2, 1024);

		if (strcmp(buff1, buff2) != 0)
		{
			std::cout << "From first file : " << buff1 << std::endl;
			std::cout << "From second file : " << buff2 << std::endl;

			break;
		}
	}
}

int main()
{
	const char file1[] = FFILENAME;
	const char file2[] = SFILENAME;

	compareContentFiles(file1, file2);

	return 0;
}