#include "Zombie.hpp"

Zombie *zombieHorde(int n, std::string name) {

    Zombie *zombies = new Zombie[n];

    for (int i = 0; i < n; i++) {
        char a = '0' + i;
        zombies[i].setZombieName(name + &a);
    }
    return zombies;
}