#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{
private:
public:
	FragTrap(void);
	FragTrap(std::string initialName);
	FragTrap(const FragTrap &);
	~FragTrap();

	FragTrap &operator=(const FragTrap &source);
	void highFivesGuys(void);
};

#endif