#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>
#include <cmath>

class Fixed
{
private:
	int fixedPointNum;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const int fixedPointValue);
	Fixed(const float fixedPointValue);
	Fixed(const Fixed &);
	~Fixed();
	float toFloat(void) const;
	int toInt(void) const;
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed &operator=(const Fixed &source);
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &source);

#endif