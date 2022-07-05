#include "Animal.hpp"

Animal::Animal(void)
{
	this->type = "animal";
	std::cout << "Animal default constructor \n";
}

Animal::Animal(const Animal &ref)
{
	*this = ref;
	std::cout << "Animal copy constructor \n";
}

Animal::~Animal(void)
{
	std::cout << "Animal destructor\n";
}

Animal &Animal::operator=(const Animal &ref)
{
	if (&ref == this)
		return *this;
	this->type = ref.type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}