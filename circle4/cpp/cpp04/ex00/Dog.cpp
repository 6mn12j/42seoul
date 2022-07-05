#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default constructor \n";
}

Dog::Dog(const Dog &ref)
{
	std::cout << "Dog copy constructor \n";
	*this = ref;
}

Dog::~Dog()
{
	std::cout << "Dog destructor \n";
}

Dog &Dog::operator=(const Dog &ref)
{
	if (&ref == this)
		return *this;
	this->type = ref.type;
	return *this;
}

void Dog::makeSound() const
{
	std::cout << "I'm Dog 멍멍....\n";
}

std::string Dog::getType(void) const
{
	return this->type;
}