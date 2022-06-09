#include "Zombie.hpp"
Zombie::Zombie() { this->name = "undefined"; }
Zombie::Zombie(std::string name) { this->name = name; }
Zombie::~Zombie() { std::cout << this->name << " has been killed\n"; }

std::string Zombie::getZombieName() { return this->name; }

void Zombie::announce(void) {
    std::cout << this->name << " : BraiiiiiiinnnzzzZ...\n";
    return;
}
