#include <iostream>
#include <fstream>
#define MAX_LEN 101
#define MAX_COUNT 30
#pragma warning (disable : 4996)

enum class Category
{
	ELECTRONICS, 
	CLOTHING, 
	BOOKS, 
	FOOD,
	BEAUTY,
	OTHER
};

struct Product
{
	char name[MAX_LEN]{};

	char deliverer[MAX_LEN]{};

	size_t quantity = 0;

	float price = 0.;

	Category category = Category::OTHER;

	void printProduct()
	{
		std::cout << "|" << name << std::endl;
		std::cout << "|" << deliverer << std::endl;
		std::cout << "|" << quantity<< std::endl;
		std::cout << "|" << price << std::endl;

		std::cout << "|";
		switch (category)
		{
		case Category::ELECTRONICS:
            std::cout << "Electronic";
			break;
		case Category::CLOTHING:
			std::cout << "Clothing";
			break;
		case Category::BOOKS:
			std::cout << "Books";
			break;
		case Category::FOOD:
			std::cout << "Food";
			break;
		case Category::BEAUTY:
			std::cout << "Beauty";
			break;
		case Category::OTHER:
			std::cout << "No Category :((";
			break;
		}

		std::cout << std::endl;
	}
};

Product initProduct()
{
	Product result;

	std::cout << '>';
	std::cin.getline(result.name, MAX_LEN);
		
	std::cout << '>';
	std::cin.getline(result.deliverer, MAX_LEN);

	std::cout << '>';
	std::cin >> result.quantity;

	std::cout << '>';
	std::cin >> result.price;

	int choice = 0;

	std::cout << '>';
	std::cin >> choice;

	switch (choice)
	{
	case 1:
	{
		result.category = Category::ELECTRONICS;
		break;
	}
	case 2:
	{
		result.category = Category::CLOTHING;
		break;
	}
	case 3:
	{
		result.category = Category::BOOKS;
		break;
	}
	case 4:
	{
		result.category = Category::FOOD;
		break;
	}
	case 5:
	{
		result.category = Category::BEAUTY;
		break;
	}
	default:
		result.category = Category::OTHER;
		break;
	}

	std::cin.ignore();

	return result;
}

struct Storage
{
	Product products[MAX_COUNT];

	size_t currCount = 0;

	void printInfo(const char* name = nullptr)
	{
		if (!name)
		{
			for (int i = 0; i < currCount; i++)
			{
				products[i].printProduct();
			}
		}
		else
		{
			for (int i = 0; i < currCount; i++)
			{
				if (strcmp(products[i].name, name) == 0)
				{
					products[i].printProduct();
					break;
				}
			}
		}
	}

	void saveProductsByCategory(const char* fileName, Category category)
	{
		if (!fileName)
			return;

		std::ofstream ofs(fileName, std::ios::binary);

		if (!ofs.is_open())
			return;

		for (int i = 0; i < currCount; i++)
		{
			if (products[i].category == category)
			{
				ofs.write((const char*)&products[i], sizeof(Product));
			}
		}

		ofs.close();
	}

	void changeQuantity(const char* name, size_t newQuantity, const char* fileName)
	{
		if (!name || !fileName)
			return;

		for (int i = 0; i < currCount; i++)
		{
			if (strcmp(products[i].name, name) == 0)
			{
				products[i].quantity = newQuantity;
				break;
			}
		}

		std::ofstream ofs(fileName, std::ios::binary);

		if (!ofs.is_open())
			return;

		ofs.write((const char*)this, currCount * sizeof(Product));

		ofs.close();
	}

	bool mySpecialStrcmp(const char* name)
	{
		if (!name)
			return false;

		for (int i = 0; i < currCount; i++)
		{
			if (strcmp(products[i].name, name) == 0)
			{
				return true;
			}
		}

		return false;
	}
};

size_t getFileSize(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();

	ifs.seekg(0, std::ios::end);

	size_t res = ifs.tellg();

	ifs.seekg(currPos);

	return res;
}

void loadStorageFromFile(const char* fileName, Storage& storage)
{
	if (!fileName)
		return;

	std::ifstream ifs(fileName, std::ios::binary);

	if (!ifs.is_open())
		return;

	size_t fileSize = getFileSize(ifs);
	size_t count = fileSize / sizeof(Product);

	if (storage.currCount + count > MAX_COUNT)
	{
		ifs.close();
		return;
	}

	storage.currCount += count;

	ifs.read((char*)&storage, storage.currCount * sizeof(Product));

	ifs.close();
}

void saveNProducts(std::ofstream& ofs, size_t n)
{
	Storage storage;

	Product product;

	for (int i = 0; i < n; i++)
	{
		product = initProduct();

		if (!storage.mySpecialStrcmp(product.name))
		{
			storage.products[storage.currCount++] = product;
		}
	}

	ofs.write((const char*)&storage, storage.currCount * sizeof(Product));

	ofs.close();
}

int main()
{
	Storage storage;

	std::ofstream ofs("load.txt", std::ios::binary);

	saveNProducts(ofs, 2);

	loadStorageFromFile("load.txt", storage);

	storage.printInfo();

	storage.printInfo("Krotka");

	storage.changeQuantity("Krotka", 13, "rasha.txt");

	storage.saveProductsByCategory("Bycat.txt", Category::ELECTRONICS);

	return 0;
}