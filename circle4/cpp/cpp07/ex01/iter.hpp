#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template <typename T>
void iter(const T *arr, int len, void (*func)(const T &data))
{
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

template <typename T>
void ftPrint(T &data)
{
	std::cout << data << " ";
}

#endif