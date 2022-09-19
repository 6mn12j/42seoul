#include "detectActualType.hpp"


bool isChar(std::string str)
{
	int len = str.length();

	if (len != 1 && len != 3 )
		return false;
	if(len == 3 && str[0] != '\'' && str[2] != '\'')
		return false;
	if (len == 1 && std::isdigit(str[0]))
		return false;
	return true;
}

#include <iostream>
int isInt(std::string str)
{
	char *end = NULL;
	long l = std::strtol(str.c_str(), &end, 10);
	if (*end == '\0')
	{
		if ( l >  std::numeric_limits<int>::max()
			|| l < std::numeric_limits<int>::min())
			return TYPE_OVERFLOW;
		return TYPE_INT;
	}
	return TYPE_ERROR;
}

bool isFloat(std::string str)
{
	char *end = NULL;
	if(std::strtod(str.c_str(), &end))
		return true;
	if (std::strlen(end) != 1 || *end != 'f' )
		return false;
	return true;
}

bool isDouble(std::string str)
{
	char *end = NULL;
	std::strtod(str.c_str(), &end);
	if (*end != '\0')
		return false;
	return true;
}


int detectActualType(std::string str)
{
	int type;

	if (str.empty())
		return TYPE_ERROR;
	if (isChar(str))
		return TYPE_CHAR;
	if ((type = isInt(str) )!=  TYPE_ERROR)
		return type;
	if (isFloat(str))
		return TYPE_FLOAT;
	if (isDouble(str))
		return TYPE_DOUBLE;
	return TYPE_ERROR;
}