#include <iostream>
#include <fstream>
#include <cstring>
#define MAX_LEN 65
#define MAX_COUNT 30
#pragma warning (disable : 4996)

size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();

	ifs.seekg(0, std::ios::end);

	size_t res = ifs.tellg();

	ifs.seekg(currPos);

	return res;
}

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

class Game
{
private:
	char _title[MAX_LEN]{};

	float _price = 0.;

	bool _isAvailable = false;

public:
	Game() = default;
	Game(const char* title, float price, bool isAvailable);

	void setTitle(const char* title);
	void setPrice(float price);
	void setAvailability(bool isAvailable);

	const char* getTitle() const;
	float getPrice() const;
	bool getAvailability() const;

	bool isFree() const;

	void print() const;

	void makeDefault();
};

class GamePlatform
{
private:
	Game games[MAX_COUNT];

	size_t currCount = 0;

public:
	void addGame(const Game& game);

	void printAt(size_t index) const;

	void print() const;

	void printMostExpensiveAndCheapestGame() const;

	void printFreeGames() const;

	void removeGame(const char* gameName);

	void saveGamePlatform(const char* fileName) const;

	void readGamePlatform(const char* fileName);
};

Game::Game(const char * title, float price, bool isAvailable)
{
	setTitle(title);
	setPrice(price);
	setAvailability(isAvailable);
}

void Game::setTitle(const char * title)
{
	if (!title)
		return;

	if (strlen(title) >= MAX_LEN)
		return;

	strcpy(_title, title);
}

void Game::setPrice(float price)
{
	if (price < 0.)
		return;

	_price = price;
}

void Game::setAvailability(bool isAvailable)
{
	_isAvailable = isAvailable;
}

const char * Game::getTitle() const
{
	return _title;
}

float Game::getPrice() const
{
	return _price;
}

bool Game::getAvailability() const
{
	return _isAvailable;
}

bool Game::isFree() const
{
	return _price < 0.00001;
}

void Game::print() const
{
	std::cout << "Title : " << _title << std::endl;
	std::cout << "Price : " << _price << std::endl;
	std::cout << "Availability : " << _isAvailable << std::endl;
}

void Game::makeDefault()
{
	_title[0] = '\0';
	_price = 0.;
	_isAvailable = false;
}

void GamePlatform::addGame(const Game & game)
{
	if (currCount == MAX_COUNT)
		return;

	games[currCount++] = game;
}

void GamePlatform::printAt(size_t index) const
{
	if (index >= currCount)
		return;

	games[index].print();
}

void GamePlatform::print() const
{
	for (int i = 0; i < currCount; i++)
	{
		games[i].print();
	}
}

void GamePlatform::printMostExpensiveAndCheapestGame() const
{
	size_t max = 0;
	size_t min = 0;

	for (int i = 1; i < currCount; i++)
	{
		if (games[max].getPrice() < games[i].getPrice())
			max = i;

		if (games[min].getPrice() > games[i].getPrice())
			min = i;
	}

	std::cout << "Most Expensive >\n";
	games[max].print();

	std::cout << "The Cheapest >\n";
	games[min].print();
}

void GamePlatform::printFreeGames() const
{
	for (int i = 0; i < currCount; i++)
	{
		if (games[i].isFree())
			games[i].print();
	}
}

void GamePlatform::removeGame(const char * gameName)
{
	if (!gameName)
		return;

	size_t index = 0;

	for (int i = 0; i < currCount; i++)
	{
		if (strcmp(games[i].getTitle(), gameName) == 0)
			index = i;
	}

	for (int i = index; i < currCount - 1; i++)
	{
		games[i] = games[i + 1];
	}

	games[currCount - 1].makeDefault();

	currCount--;
}

void GamePlatform::saveGamePlatform(const char * fileName) const
{
	if (!fileName)
		return;

	std::ofstream ofs(fileName);

	if (!ofs.is_open())
		return;

	for (int i = 0; i < currCount; i++)
	{
		ofs << (games[i].getTitle()) << ',' << games[i].getPrice() << ',' << games[i].getAvailability();

		if (i != currCount - 1)
			ofs << std::endl;
	}
}

void GamePlatform::readGamePlatform(const char* fileName)
{
	if (!fileName)
		return;

	std::ifstream ifs(fileName);

	if (!ifs.is_open())
		return;

	size_t size = getCountOfSymbolInFile(ifs, '\n') + 1;

	if (currCount + size > MAX_COUNT)
		return;

	char buff[MAX_LEN]{};
	float price = 0.;
	bool isAvailable = false;


	for (int i = currCount; i < (currCount + size); i++)
	{
		ifs.getline(buff, MAX_LEN, ',');
		games[i].setTitle(buff);

		ifs >> price;
		games[i].setPrice(price);

		ifs.ignore();

		ifs >> isAvailable;
		games[i].setAvailability(isAvailable);

		ifs.ignore();
	}

	currCount += size;

	ifs.close();
}

int main()
{
	GamePlatform platform;

	Game gm1("OMG1", 69.69, 1);
	Game gm2("OMG2", 95.99, 0);

	platform.addGame(gm1);
	platform.addGame(gm2);

	platform.print();

	platform.printAt(1);

	platform.printFreeGames();

	platform.printMostExpensiveAndCheapestGame();

	platform.saveGamePlatform("gp.txt");

	platform.removeGame("OMG1");

	platform.readGamePlatform("gp.txt");

	platform.print();

	return 0;
}