#include "WrongCat.hpp"

WrongCat::WrongCat()
{
	this->type = "WrongCat";
	std::cout << "WrongCat default constructor \n";
}

WrongCat::WrongCat(const WrongCat &ref)
{
	*this = ref;
	std::cout << "WrongCat copy constructor \n";
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor \n";
}

WrongCat &WrongCat::operator=(const WrongCat &ref)
{
	if (&ref == this)
		return *this;
	this->type = ref.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "I'm WrongCat 야옹....\n";
}

std::string WrongCat::getType(void) const
{
	return this->type;
}