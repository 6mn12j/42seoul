#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <limits>

class Span
{
private:
	unsigned int n;
	std::vector<int> span;

public:
	Span(void);
	Span(unsigned int n);
	Span(const Span &);
	~Span(void);
	Span &operator=(const Span &);

	void addNumber(int n);
	unsigned int shortestSpan();
	unsigned int longestSpan();

	class SizeException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
};

#endif