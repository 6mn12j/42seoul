#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &);
	Cat &operator=(const Cat &);

	void makeSound(void) const;
	void setIdea(unsigned int index, std::string idea) const;
	void printIdea(unsigned int index) const;
};

#endif