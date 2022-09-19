#include "Convert.hpp"

Convert::Convert() : raw("undefined"),isPrint(true),type(0),i(0),c(0),f(0.0f),d(0.0)
{
	// std::cout << "Default Constructor" << std::endl;
}

Convert::~Convert()
{
	// std::cout << "Default Destructor" << std::endl;
}

Convert::Convert(const Convert &ref)
{
	*this = ref;
}

Convert &Convert::operator=(const Convert &ref)
{
	if (&ref == this)
		return *this;
	this->raw = ref.raw;
	this->isPrint = ref.isPrint;
	this->type = ref.type;
	this->i = ref.i;
	this->c = ref.c;
	this->f = ref.f;
	this->d = ref.d;
	return *this;
}

Convert::Convert(std::string str) : raw(str),isPrint(true),type(TYPE_ERROR),i(0),c(0),f(0.0f),d(0.0)
{
	this->type = detectActualType(str);
	this->convertActualType();
	this->convertToScalaType();

}


void Convert:: printChar()
{
	std::cout << "char: ";
	if (this->type == TYPE_ERROR || !this->isPrint)
		std::cout <<"impossible" ;
	else if(!(this->c >= 32 && this->c <=126))
		std::cout << "Non displayable" ;
	else
		 std::cout << '\'' << this->c << '\'';
  std::cout << std::endl;

}

void Convert::printInt()
{
	std::cout << "int: ";
	if(this->type == TYPE_ERROR
	 || this->i > std::numeric_limits<int>::max()
  	 || this->i < std::numeric_limits<int>::min())
		std::cout << "impossible";
	else
		std::cout << static_cast<int>(this->i);
	 std::cout << std::endl;
}

void Convert::printFloat()
{
	std::cout << "float: ";
 	if (this->type == TYPE_ERROR || this->type == TYPE_OVERFLOW)
    	std::cout << "impossible";
  	else
    	std::cout << std::fixed << std::setprecision(1) << this->f << "f";
  	std::cout <<  std::endl;
}

void Convert::printDouble()
{
	std::cout << "double: ";
  	if (this->type == TYPE_ERROR || this->type == TYPE_OVERFLOW)
    	std::cout << "impossible";
  	else
    	std::cout << std::fixed << std::setprecision(1) << this->d;
  	std::cout << std::endl;
}

void Convert::printAll()
{
	printChar();
	printInt();
	printFloat();
	printDouble();
}

void Convert::convertToScalaType()
{
	if (this->type == TYPE_CHAR)
	{
		this->i = static_cast<long>(this->c);
		this->f = static_cast<float>(this->c);
		this->d = static_cast<double>(this->c);
	}
	else if (this->type == TYPE_INT)
	{
		if((static_cast<int>(this->i) > std::numeric_limits<char>::max())
  	 		|| (static_cast<int>(this->i) < std::numeric_limits<char>::min()))
	   		this->isPrint = false;
		else
			this->c = static_cast<char>(this->i);
		this->f = static_cast<float>(this->i);
		this->d = static_cast<double>(this->i);
	}
	else if (this->type == TYPE_FLOAT)
	{
		if((static_cast<int>(this->f) > std::numeric_limits<char>::max())
  	 		|| (static_cast<int>(this->f) < std::numeric_limits<char>::min()))
			   this->isPrint = false;
		else
			this->c = static_cast<char>(this->f);
		this->i = static_cast<long>(this->f);
		this->d = static_cast<double>(this->f);
	}
	else if (this->type == TYPE_DOUBLE)
	{
		if((static_cast<int>(this->d) > std::numeric_limits<char>::max())
  	 		|| (static_cast<int>(this->d) < std::numeric_limits<char>::min()))
	   		this->isPrint = false;
		else
			this->c = static_cast<char>(this->d);
		this->i = static_cast<long>(this->d);
		this->d = static_cast<float>(this->d);
	}

}

void Convert::convertActualType()
{
	if(this->type == TYPE_CHAR)
	{
		if(this->raw.length() == 3)
			this->c = raw[1];
		else
			this->c = raw[0];
	}
	else if (this->type == TYPE_INT)
		this->i = std::strtol(this->raw.c_str(), NULL, 10);
	else if (this->type == TYPE_FLOAT)
		this->f = static_cast<float>(std::strtod(this->raw.c_str(), NULL));
	else if (this->type == TYPE_DOUBLE)
		this->d = std::strtod(this->raw.c_str(), NULL);
}