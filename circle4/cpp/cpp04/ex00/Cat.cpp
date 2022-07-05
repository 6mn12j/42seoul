#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default constructor \n";
}

Cat::Cat(const Cat &ref)
{
	std::cout << "Cat copy constructor \n";
	*this = ref;
}

Cat::~Cat()
{
	std::cout << "Cat destructor \n";
}

Cat &Cat::operator=(const Cat &ref)
{
	if (&ref == this)
		return *this;
	this->type = ref.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "I'm Cat 야옹....\n";
}
