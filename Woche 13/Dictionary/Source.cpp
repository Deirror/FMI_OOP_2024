#include <iostream>
#include "Dictionary.hpp"

int main()
{
	Dictionary<int> dict;

	dict.add("1", 34);
	dict.add("2", 12);
	dict.add("3", 55);
	dict.add("4", 66);
	dict.add("5", 44);
	dict.removeByKey("4");

	dict.clear();

	std::cout << dict.getByKey("3");
}