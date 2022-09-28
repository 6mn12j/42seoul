#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <exception>
class NotFoundExeception : public std::exception
{
	virtual const char *what(void) const throw()
	{
		return "value  not found";
	}
};

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	typename T::iterator iter;

	iter = std::find(container.begin(), container.end(), value);
	if (iter == container.end())
		throw NotFoundExeception();

	return iter;
}

#endif