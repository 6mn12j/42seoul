#ifndef FIXED_HPP
#define FIXED_HPP
#include <iostream>

class Fixed
{
private:
	int fixedPointNum;
	static const int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &);
	~Fixed();
	int getRawBits(void) const;
	void setRawBits(int const raw);
	Fixed &operator=(const Fixed &source);
};

#endif