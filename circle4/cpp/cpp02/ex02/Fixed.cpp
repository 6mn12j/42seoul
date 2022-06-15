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

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (&source == this)
		return *this;
	this->fixedPointNum = source.getRawBits();
	return *this;
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
	//고정 -> 부동으로 보여줘라
	return ostream << source.toFloat();
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

Fixed Fixed::operator++(int value)
{
	Fixed temp = *this;
	this->fixedPointNum += value;
	return temp;
}

Fixed Fixed::operator--(int value)
{
	Fixed temp = *this;
	this->fixedPointNum -= value;
	return temp;
}

Fixed &min(Fixed &a1, Fixed &a2)
{
	if (a1 > a2)
		return a2;
	else
		return a1;
}

Fixed &max(Fixed &a1, Fixed &a2)
{
	if (a1 < a2)
		return a2;
	else
		return a1;
}

const Fixed &min(const Fixed &a1, const Fixed &a2)
{
	if (a1.toFloat() > a2.toFloat())
		return a2;
	else
		return a1;
}

const Fixed &max(const Fixed &a1, const Fixed &a2)
{
	if (a1.toFloat() < a2.toFloat())
		return a2;
	else
		return a1;
}
