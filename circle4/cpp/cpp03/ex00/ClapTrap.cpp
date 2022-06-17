#include "ClapTrap.hpp"
ClapTrap::ClapTrap() : name("undefined"), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << this->name << " ClapTrap defatult Constructor " << std::endl;
}

ClapTrap::ClapTrap(std::string initialName) : name(initialName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << this->name << "ClapTrap Constructor " << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap " << this->name << " is killed " << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
{
	*this = source;
}

std::string ClapTrap::getName() const
{
	return this->name;
}

int ClapTrap::getHitPoints(void) const
{
	return this->hitPoints;
}

int ClapTrap::getEnergyPoints(void) const
{
	return this->energyPoints;
}

int ClapTrap::getAttackDamage() const
{
	return this->attackDamage;
}

bool ClapTrap::canAnything(void)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "No hit Points" << std::endl;
		return false;
	}

	if (this->energyPoints <= 0)
	{
		std::cout << "No energy Points" << std::endl;
		return false;
	}
	return true;
}

void ClapTrap::attack(const std::string &target)
{
	if (!canAnything())
		return;
	this->energyPoints--;

	std::cout << "ClapTrap " << this->name;
	std::cout << " attacks " << target << ",";
	std::cout << " causing " << this->attackDamage;
	std::cout << " points of damage! " << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (this->hitPoints <= 0)
	{
		std::cout << "No hit Points" << std::endl;
		return;
	}

	this->hitPoints -= amount;

	std::cout << "ClapTrap " << this->name;
	std::cout << " take damage " << amount << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (!canAnything())
		return;
	this->energyPoints--;

	this->hitPoints += amount;
	std::cout << "ClapTrap " << this->name;
	std::cout << " repaired HitsPoints " << amount << std::endl;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
	if (&source == this)
		return *this;
	this->name = source.getName();
	this->hitPoints = source.getHitPoints();
	this->energyPoints = source.getEnergyPoints();
	this->attackDamage = source.getAttackDamage();
	return *this;
}