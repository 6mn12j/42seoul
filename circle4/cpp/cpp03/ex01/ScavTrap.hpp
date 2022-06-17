#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap(void);
	ScavTrap(std::string initialName);
	ScavTrap(const ScavTrap &);
	~ScavTrap();

	ScavTrap &operator=(const ScavTrap &target);
	void attack(const std::string &target);
	void guardGate(void);
};

#endif