#include "Fixed.hpp"

Fixed::Fixed() : fixedPointNum(0)
{}

Fixed::Fixed(const int fixedPointValue) : fixedPointNum(fixedPointValue << fractionalBits)
{}

Fixed::Fixed(const float fixedPointValue)
{
	this->fixedPointNum = (int)roundf(fixedPointValue * (1 << fractionalBits));
}

Fixed::Fixed(const Fixed &source)
{
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
}

int Fixed::getRawBits(void) const
{
	return this->fixedPointNum;
}

Fixed::~Fixed()
{}

Fixed &Fixed::operator=(const Fixed &source)
{
	if (&source == this)
		return *this;
	this->fixedPointNum = source.getRawBits();
	return *this;
}

bool Fixed::operator>(const Fixed &fixedValue)
{
	return this->toFloat() > fixedValue.toFloat();
}

bool Fixed::operator<(const Fixed &fixedValue)
{
	return this->toFloat() < fixedValue.toFloat();
}

bool Fixed::operator>=(const Fixed &fixedValue)
{
	return this->toFloat() >= fixedValue.toFloat();
}

bool Fixed::operator<=(const Fixed &fixedValue)
{
	return this->toFloat() <= fixedValue.toFloat();
}

bool Fixed::operator==(const Fixed &fixedValue)
{
	return this->toFloat() == fixedValue.toFloat();
}

bool Fixed::operator!=(const Fixed &fixedValue)
{
	return this->toFloat() != fixedValue.toFloat();
}

Fixed Fixed::operator+(const Fixed &fixedValue)
{
	return Fixed(this->toFloat() + fixedValue.toFloat());
}

Fixed Fixed::operator-(const Fixed &fixedValue)
{
	return Fixed(this->toFloat() - fixedValue.toFloat());
}

Fixed Fixed::operator/(const Fixed &fixedValue)
{
	return Fixed(this->toFloat() / fixedValue.toFloat());
}

Fixed Fixed::operator*(const Fixed &fixedValue)
{
	return Fixed(this->toFloat() * fixedValue.toFloat());
}

Fixed &Fixed::operator++(void)
{
	this->fixedPointNum++;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	this->fixedPointNum--;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->fixedPointNum ++;
	return temp;
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->fixedPointNum --;
	return temp;
}

Fixed &Fixed::min(Fixed &a1, Fixed &a2)
{
	if (a1 > a2)
		return a2;
	else
		return a1;
}

Fixed &Fixed::max(Fixed &a1, Fixed &a2)
{
	if (a1 < a2)
		return a2;
	else
		return a1;
}

const Fixed &Fixed::min(const Fixed &a1, const Fixed &a2)
{
	if (a1.toFloat() > a2.toFloat())
		return a2;
	else
		return a1;
}

const Fixed &Fixed::max(const Fixed &a1, const Fixed &a2)
{
	if (a1.toFloat() < a2.toFloat())
		return a2;
	else
		return a1;
}

std::ostream &operator<<(std::ostream &ostream, const Fixed &source)
{
	return ostream << source.toFloat();
}
