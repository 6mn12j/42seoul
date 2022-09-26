#include "Span.hpp"

Span::Span(void):n(0)
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

Span &Span::operator=(const Span& ref)
{
	if(this == &ref)
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

unsigned int Span::shortestSpan()
{

	if (this->span.size() < 2)
		throw SizeException();

	long long result = INT_MAX;
	int prev;

	std::sort(this->span.begin(), this->span.end());
	for(std::vector<int>::iterator iter = this->span.begin(); iter != this->span.end(); iter++)
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
	int min = *min_element(this->span.begin(),this->span.end());
	return (max - min);
}

const char *Span::StoreValueException::what(void) const throw()
{
    return "Already elements stored \n";
}

const char *Span::SizeException::what(void) const throw()
{
    return "Vector size is not enough\n";
}