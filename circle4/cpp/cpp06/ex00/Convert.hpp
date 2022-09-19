#ifndef CONVERT_HPP
#define CONVERT_HPP

#include <string>
#include <cstring>
#include <iostream>
#include <iomanip>
#include "detectActualType.hpp"

/*
	type :
	error char int float double
*/
#define TYPE_ERROR 0
#define TYPE_CHAR 1
#define TYPE_INT 2
#define TYPE_FLOAT 3
#define TYPE_DOUBLE 4
#define TYPE_OVERFLOW 5

class Convert
{
private:
	std::string raw;
	bool isPrint;
	int type;
	long  i;
	char c;
	float f;
	double d;

public:
	Convert();
	Convert(std::string str);
	Convert(const Convert &);
	Convert &operator=(const Convert &);
	~Convert();

	void printAll();
	void printChar();
	void printInt();
	void printFloat();
	void printDouble();
	void convertActualType();
	void convertToScalaType();


};

#endif