#include "Cat.hpp"

Cat::Cat()
{
	this->type = "Cat";
	std::cout << "Cat default constructor \n";
	this->brain = new Brain();
}

Cat::Cat(const Cat &ref)
{
	std::cout << "Cat copy constructor \n";
	this->brain = new Brain();
	*this = ref;
}

Cat::~Cat()
{
	delete this->brain;
	std::cout << "Cat destructor \n";
}

Cat &Cat::operator=(const Cat &ref)
{
	if (&ref == this)
		return *this;
	this->type = ref.type;
	*(this->brain) = *(ref.brain);

	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "I'm Cat 야옹....\n";
}

std::string Cat::getType(void) const
{
	return this->type;
}

void Cat::setIdea(unsigned int index, std::string idea) const
{
	this->brain->setIdea(index, idea);
}

void Cat::printIdea(unsigned int index) const
{
	this->brain->printIdea(index);
}