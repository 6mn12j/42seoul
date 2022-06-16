#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int fixedPointValue) : fixedPointNum(fixedPointValue << fractionalBits)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float fixedPointValue)
{
	std::cout << "Float constructor called" << std::endl;

	this->fixedPointNum = (int)roundf(fixedPointValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &source)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = source;
}

float Fixed::toFloat(void) const
{
	return ((float)this->fixedPointNum / (float)(1 << fractionalBits));
}

int Fixed::toInt(void) const
{
	return (int)roundf(this->fixedPointNum / (1 << fractionalBits));
}

void Fixed::setRawBits(int const raw)
{
	this->fixedPointNum = raw;
	std::cout << "setRawBits member function clled" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->fixedPointNum;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &source)
{
	return ostream << source.toFloat();
}

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&source == this)
		return *this;
	this->fixedPointNum = source.getRawBits();
	return *this;
}
