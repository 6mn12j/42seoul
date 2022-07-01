#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	virtual ~Animal(void);
	Animal(const Animal &);
	Animal &operator=(const Animal &);

	std::string getType(void) const;
	virtual void makeSound(void) const;
};

#endif