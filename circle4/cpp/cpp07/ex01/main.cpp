#include "iter.hpp"
#include <string>
#include <iostream>

int main(void)
{
	{
		int array[] = {1, 2, 3, 4, 5};
		iter(array, sizeof(array) / sizeof(int), ftPrint);
	}

	std::cout << std::endl;

	{
		double array[] = {0.1, 0.2, 0.3, 0.4, 0.5};
		iter(array, sizeof(array) / sizeof(double), ftPrint);
	}

	std::cout << std::endl;

	{
		std::string array[] = {"a", "b", "c", "d", "e"};
		iter(array, sizeof(array) / sizeof(std::string), ftPrint);
	}

	return 0;
}