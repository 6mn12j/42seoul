#include "Dog.hpp"

Dog::Dog()
{
	this->type = "Dog";
	std::cout << "Dog default constructor \n";
	this->brain = new Brain();
}

Dog::Dog(const Dog &ref)
{
	std::cout << "Dog copy constructor \n";
	this->brain = new Brain();
	*this = ref;
}

Dog::~Dog()
{
	delete this->brain;
	std::cout << "Dog destructor \n";
}

Dog &Dog::operator=(const Dog &ref)
{
	if (&ref == this)
		return *this;
	this->type = ref.type;

	*(this->brain) = *(ref.brain);

	return *this;
}

void Dog::makeSound() const
{
	std::cout << "I'm Dog 멍멍....\n";
}

void Dog::setIdea(unsigned int index, std::string idea) const
{
	this->brain->setIdea(index, idea);
}

void Dog::printIdea(unsigned int index) const
{
	this->brain->printIdea(index);
}