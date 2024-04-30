#include <iostream>
#include <fstream>
#define FILENAME "selfPrintingCode.cpp"

void printCode()
{
	std::ifstream ifs(FILENAME);

	if (!ifs.is_open())
		return;
	
	char buff[1024]{};

	while (!ifs.eof())
	{
		ifs.getline(buff, 1024);

		std::cout << buff << std::endl;
	}
}

int main()
{
	printCode();

	return 0;
}