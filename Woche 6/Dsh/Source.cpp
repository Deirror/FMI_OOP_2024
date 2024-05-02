#include <iostream>
#include "NumberSeries.h"

int main()
{
	NumberSeries ns(-1, [](int a) -> int {return a + 1;});

	std::cout << ns.generateINumber(112) << std::endl;

	std::cout << ns.isNumberFromSeries(3);

	return 0;
}