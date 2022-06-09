#include "Zombie.hpp"
int main(void) {
    Zombie *zombie;

    zombie = newZombie("minjupar");
    zombie->announce();
    randomChump("polarbear");
    delete zombie;
    return 0;
}