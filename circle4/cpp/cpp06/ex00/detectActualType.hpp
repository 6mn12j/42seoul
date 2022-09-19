#ifndef DETECT_ACTUAL_TYPE_HPP
#define DETECT_ACTUAL_TYPE_HPP


#include <limits>
#include <string>
#include <cstdlib>

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


int detectActualType(std::string str);

#endif