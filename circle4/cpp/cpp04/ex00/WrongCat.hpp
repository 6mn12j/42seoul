#ifndef WRONG_CAT_HPP
#define WRONG_CAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:
	WrongCat(void);
	~WrongCat(void);
	WrongCat(const WrongCat &);
	WrongCat &operator=(const WrongCat &);

	void makeSound(void) const;
};

#endif