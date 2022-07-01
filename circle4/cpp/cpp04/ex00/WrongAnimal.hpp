#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <string>
#include <iostream>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(void);
	~WrongAnimal(void);
	WrongAnimal(const WrongAnimal &);
	WrongAnimal &operator=(const WrongAnimal &);

	std::string getType(void) const;
	void makeSound(void) const;
};

#endif