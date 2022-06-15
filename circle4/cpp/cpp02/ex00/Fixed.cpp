#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&source == this)
		return *this;
	this->fixedPointNum = source.getRawBits();
	return *this;
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointNum = raw;
	std::cout << "setRawBits member function clled" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function clled" << std::endl;
	return this->fixedPointNum;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}