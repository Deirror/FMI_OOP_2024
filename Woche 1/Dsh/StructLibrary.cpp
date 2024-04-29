#include <iostream>
#define MAX_LEN 50
#define MAX_COUNT 30

enum class Genre
{
	Roman,
	Historical,
	Poetry,
	Other
};

struct Book
{
	char title[MAX_LEN]{};

	char author[MAX_LEN]{};

	Genre genre = Genre::Other;

	size_t quantity = 0;

	void printBook()
	{
		std::cout << "Title : " << title << '\n';

		std::cout << "Author : " << author << '\n';

		switch (genre)
		{
		case Genre::Roman:
		{
			std::cout << "Roman";
			break;
		}
		case Genre::Poetry:
		{
			std::cout << "Poetry";
			break;
		}
		case Genre::Historical:
		{
			std::cout << "Historical";
			break;
		}
		default:
		{
			std::cout << "No genre :((";
		}
		}

		std::cout << std::endl;
		std::cout << quantity << std::endl;
	}

	bool isAllTaken()
	{
		return quantity == 0;
	}
};

Book initBook()
{
	Book result;
	std::cout << '>';
	std::cin.getline(result.title, MAX_LEN);
	std::cout << '>';
	std::cin.getline(result.author, MAX_LEN);

	char genre;

	std::cout << '>';
	std::cin >> genre;

	switch (genre)
	{
	case'r':
	{
		result.genre = Genre::Roman;
		break;
	}
	case'h':
	{
		result.genre = Genre::Historical;
		break;
	}
	case'p':
	{
		result.genre = Genre::Poetry;
		break;
	}
	}

	std::cout << '>';
	std::cin >> result.quantity;

	return result;
}

struct Library
{
	Book books[MAX_COUNT];

	size_t currSize = 0;

	bool addBook(const Book& obj)
	{
		if (currSize == MAX_COUNT)
			return false;

		books[currSize++] = obj;

		return true;
	}

	void printInfo()
	{
		for (int i = 0; i < currSize; i++)
		{
			books[i].printBook();
		}
	}

	void takeBook(const char* bookName)
	{
		if (!bookName)
			return;

		size_t index = findBook(bookName);

		if (index == -1)
			return;

		if (books[index].isAllTaken())
			return;

		books[index].quantity--;
	}

	void returnBook(const char* bookName)
	{
		if (!bookName)
			return;

		size_t index = findBook(bookName);

		if (index == -1)
			return;

		books[index].quantity++;
	}

	size_t findBook(const char* bookName)
	{
		if (!bookName)
			return -1;

		for (size_t i = 0; i < currSize; i++)
		{
			if (strcmp(books[i].title, bookName) == 0)
				return i;
		}

		return -1;
	}
};

int main()
{
	Library library;

	library.addBook(initBook());
	library.addBook(initBook());

	library.takeBook("Herliches, Deirror");
	//
	size_t index = library.findBook("Herliches, Deirror");
	//
	library.books[index].printBook();
	//
	library.returnBook("Herliches, Deirror");
	//
	library.books[index].printBook();

	return 0;
}