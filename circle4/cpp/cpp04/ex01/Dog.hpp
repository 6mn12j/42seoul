#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog(void);
	~Dog(void);
	Dog(const Dog &);
	Dog &operator=(const Dog &);

	void makeSound(void) const;

	void setIdea(unsigned int, std::string idea) const;
	void printIdea(unsigned int index) const;
};

#endif