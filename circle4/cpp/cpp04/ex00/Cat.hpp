#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	~Cat(void);
	Cat(const Cat &);
	Cat &operator=(const Cat &);

	void makeSound(void) const;
	std::string getType(void) const;
};

#endif