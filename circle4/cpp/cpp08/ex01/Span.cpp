#include "Span.hpp"

Span::Span(void) : n(0)
{
	// std::cout << "Default Constucrot\n";
}

Span::Span(unsigned int n)
{
	this->span.reserve(n);
	this->n = n;
	// std::cout << "Constucrot\n";
}

Span::Span(const Span &ref)
{
	*this = ref;
}

Span &Span::operator=(const Span &ref)
{
	if (this == &ref)
		return *this;
	this->n = ref.n;
	this->span = ref.span;
	return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
	if (this->span.size() + 1 > this->n)
		throw SizeException();
	this->span.push_back(n);
}

void Span::addNumber()
{
	if (this->n <= 1)
		throw SizeException();
	srand(time(NULL));
	std::vector<int> temp(this->n);
	for (std::vector<int>::iterator iter = temp.begin(); iter != temp.end(); iter++)
		*iter = rand();
	std::sort(temp.begin(), temp.end());
	this->span = temp;

}

unsigned int Span::shortestSpan()
{

	if (this->span.size() < 2)
		throw SizeException();

	long result = UINT_MAX;
	int prev;

	std::sort(this->span.begin(), this->span.end());
	for (std::vector<int>::iterator iter = this->span.begin(); iter != this->span.end(); iter++)
	{
		if (iter == this->span.begin())
		{
			prev = *iter;
		}
		else
		{
			if (result > *iter - prev)
				result = *iter - prev;
			prev = *iter;
		}
	}

	return static_cast<unsigned int>(result);
}

unsigned int Span::longestSpan()
{

	if (this->span.size() < 2)
		throw SizeException();

	int max = *max_element(this->span.begin(), this->span.end());
	int min = *min_element(this->span.begin(), this->span.end());
	return (max - min);
}

unsigned int Span::size()
{
	return this->n;
}



const char *Span::SizeException::what(void) const throw()
{
	return "Vector size is not enough\n";
}
