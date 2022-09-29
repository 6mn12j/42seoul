#include <algorithm>
#include <vector>
#include <deque>
#include <list>
#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> intVector;
	std::deque<int> intDeque;
	std::list<int> intList;
	for (int i = 0; i < 10; i++)
	{
		intVector.push_back(i);
		intDeque.push_back(i);
		intList.push_back(i);
	}
	try
	{
		std::cout << *(easyfind(intVector, 6)) << " is at " << std::distance(intVector.begin(), easyfind(intVector, 6)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *(easyfind(intDeque, 0)) << " is at " << std::distance(intDeque.begin(), easyfind(intDeque, 0)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		std::cout << *(easyfind(intList, 10)) << " is at " << std::distance(intList.begin(), easyfind(intList, 10)) << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
