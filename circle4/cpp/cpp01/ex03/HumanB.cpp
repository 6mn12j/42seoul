#include "HumanB.hpp"

HumanB::HumanB(std::string name) {
    this->name = name;
    this->weapon = NULL;
}

void HumanB::attack() {
    std::cout << this->name;
    std::cout << " attacks with their ";
    if (this->weapon != NULL)
        std::cout << this->weapon->getType() << std::endl;
    else
        std::cout << "fist" << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) { this->weapon = &weapon; }
