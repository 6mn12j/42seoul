#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	this->type = "WrongAnimal";
	std::cout << "WrongAnimal default constructor \n";
}

WrongAnimal::WrongAnimal(const WrongAnimal &ref)
{
	*this = ref;
	std::cout << "WrongAnimal copy constructor \n";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal destructor\n";
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &ref)
{
	if (&ref == this)
		return *this;
	this->type = ref.type;
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "I'm WrongAnimal\n";
}