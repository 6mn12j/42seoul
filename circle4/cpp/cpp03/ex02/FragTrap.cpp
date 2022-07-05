#include "FragTrap.hpp"

FragTrap::FragTrap()
{
	this->name = "undefined";
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << this->getName() << " FragTrap default Constructor " << std::endl;
}

FragTrap::FragTrap(std::string initialName)
{
	this->name = initialName;
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << this->getName() << " FragTrap Constructor " << std::endl;
}

FragTrap::FragTrap(const FragTrap &source)
{
	std::cout << this->getName() << " FragTrap Copy Constructor " << std::endl;
	*this = source;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap " << this->name << " is killed " << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &source)
{
	if (this == &source)
		return *this;
	this->name = source.name;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	this->attackDamage = source.attackDamage;
	return *this;
}

void FragTrap::highFivesGuys(void)
{
	std::cout << "FragTrap " << this->name << " highfivesGuys. " << std::endl;
}