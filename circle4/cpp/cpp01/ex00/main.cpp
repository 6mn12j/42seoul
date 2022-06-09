#include "Zombie.hpp"
int main(void) {
    Zombie *zombie;

    randomChump("polarbear");
    zombie = newZombie("minjupar");
    zombie->announce();
    delete zombie;
    return 0;
}