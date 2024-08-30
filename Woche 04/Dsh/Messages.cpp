#include <iostream>
#include <fstream>

struct User
{
	char name[25]{};
};

struct Message
{
	User from;
	char* text;
};

void printChat(const char* filePath)
{
	if (!filePath)
		return;

	std::ifstream ifs(filePath, std::ios::binary);

	if (!ifs.is_open())
		return;

	Message msg;

	size_t textSize = 0;


	while (true)
	{
		ifs.read((char*)&msg.from, sizeof(User));

		ifs.read((char*)&textSize, sizeof(size_t));

		msg.text = new char[textSize + 1]{};

		ifs.read((char*)msg.text, textSize);

		std::cout << "<" << msg.from.name << "> " << *msg.text;

		delete[] msg.text;

		if (ifs.eof())
			break;
	}

}

int main()
{
	printChat("msg.dat");

	return 0;
}