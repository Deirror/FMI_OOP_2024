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

	ofs << number1 + number2 << ' ' << number1 - number2;

	ofs.close();
}

void readNumbersFromFile()
{
	std::ifstream ifs(FILENAME, std::ios::in);

	if (!ifs.is_open())
		return;

	int sum, diff;

	ifs >> sum >> diff;

	ifs.close();

	int orgNum2 = (sum - diff) / 2;

	int orgNum1 = sum - orgNum2;

	std::cout << orgNum1 << ' ' << orgNum2;
}

int main()
{
	readNumbersAndSaveToFile();

	readNumbersFromFile();

	return 0;
}