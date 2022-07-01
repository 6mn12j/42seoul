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
	return *this;
}

void Brain::setIdea(std::string idea)
{
	(void)idea;
	for (int i = 0; i < 100; i++)
	{
		std::cout << this->ideas[i];
		std::cout << i << std::endl;
	}
}