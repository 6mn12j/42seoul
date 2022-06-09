#include "Zombie.hpp"

int main(void) {
    int n = 5;
    std::cout << "---------Horde-------------\n";

    Zombie *zombies = zombieHorde(n, "anonymousZombie");
    for (int i = 0; i < n; i++)
        zombies[i].announce();
    delete[] zombies;
}