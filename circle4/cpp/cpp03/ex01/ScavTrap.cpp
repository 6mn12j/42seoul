#include "ScavTrap.hpp"

ScavTrap::ScavTrap()
{
	std::cout << this->getName() << " ScavTrap default Constructor " << std::endl;
}

ScavTrap::ScavTrap(std::string initialName)
{
	this->name = initialName;
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << this->getName() << " ScavTrap Constructor " << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source)
{
	*this = source;
}

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap " << this->name << " is killed " << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
	this->name = source.name;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	this->attackDamage = source.attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (!canAnything())
		return;
	this->energyPoints--;

	std::cout << "ScavTrap " << this->name;
	std::cout << " attacks " << target << ",";
	std::cout << " causing " << this->attackDamage;
	std::cout << " points of damage! " << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap " << this->name << " Gate keeper mode. " << std::endl;
}