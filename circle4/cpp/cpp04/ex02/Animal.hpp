#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <sstream>
#include <iostream>

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(const Animal &);
	virtual ~Animal(void);
	virtual Animal &operator=(const Animal &);

	virtual std::string getType(void) const = 0;
	virtual void makeSound(void) const = 0;
};

#endif