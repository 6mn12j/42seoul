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
	bool operator>(const Fixed &fixedValue);
	bool operator<(const Fixed &fixedValue);
	bool operator>=(const Fixed &fixedValue);
	bool operator<=(const Fixed &fixedValue);
	bool operator==(const Fixed &fixedValue);
	bool operator!=(const Fixed &fixedValue);

	Fixed operator+(const Fixed &fixedValue);
	Fixed operator-(const Fixed &fixedValue);
	Fixed operator*(const Fixed &fixedValue);
	Fixed operator/(const Fixed &fixedValue);

	Fixed &operator++(void);
	Fixed operator++(int value);
	Fixed &operator--(void);
	Fixed operator--(int value);

	static Fixed &min(Fixed &a1, Fixed &a2);
	static const Fixed &min(const Fixed &a1, const Fixed &a2);
	static Fixed &max(Fixed &a1, Fixed &a2);
	static const Fixed &max(const Fixed &a1, const Fixed &a2);
};

std::ostream &operator<<(std::ostream &ostream, const Fixed &source);

#endif