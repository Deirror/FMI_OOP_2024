#include <iostream>
#include <fstream>
#define FILENAME "result1.txt"

void readNumbersAndSaveToFile()
{
	int number1, number2;

	std::cin >> number1 >> number2;

	std::ofstream ofs(FILENAME, std::ios::out);

	if (!ofs.is_open())
		return;

	ofs << number1 << ' ' << number2;

	ofs.close();
}

void readNumbersFromFile()
{
	std::ifstream ifs(FILENAME, std::ios::in);

	if (!ifs.is_open())
		return;

	int number1, number2;

	ifs >> number1 >> number2;

	ifs.close();

	std::cout << number1 << ' ' << number2;
}

int main()
{
	readNumbersAndSaveToFile();

	readNumbersFromFile();

	return 0;
}