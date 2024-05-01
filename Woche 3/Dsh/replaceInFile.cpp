#include <iostream>
#include <fstream>

void replaceSymbolsInFile(std::fstream& file, char ch, char toRepalce)
{
	while (!file.eof())
	{
		char currentSybmol = file.get();

		if (currentSybmol != ch)
			continue;

		file.seekp(-1, std::ios::cur);
		file.put(toRepalce);
		file.flush();
	}

	file.close();
}

void replaceSymbolsInFile(const char* fileName, char symbol, char toRepalce)
{
	if (!fileName)
		return;

	std::fstream fs(fileName, std::ios::in | std::ios::out);

	if (!fs.is_open())
		return;

	replaceSymbolsInFile(fs, symbol, toRepalce);
}

int main()
{
	replaceSymbolsInFile("omg.txt", 'a', 'm');

	return 0;
}