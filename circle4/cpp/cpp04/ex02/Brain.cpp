#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain default constructor \n";
}

Brain::Brain(const Brain &ref)
{
	*this = ref;
	std::cout << "Brain copy constructor \n";
}

Brain::~Brain(void)
{
	std::cout << "Brain destructor\n";
}

Brain &Brain::operator=(const Brain &ref)
{
	if (&ref == this)
		return *this;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = ref.ideas[i];
	return *this;
}

void Brain::setIdea(unsigned int index, std::string idea)
{
	this->ideas[index] = idea;
}

void Brain::printIdea(unsigned int index)
{
	std::cout << this->ideas[index];
	std::cout << std::endl;
}