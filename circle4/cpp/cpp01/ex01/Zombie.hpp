#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
  private:
    std::string name;

  public:
    void announce(void);
    std::string getZombieName();
    void setZombieName(std::string name);
    Zombie();
    Zombie(std::string);
    ~Zombie();
};

void randomChump(std::string name);
Zombie *zombieHorde(int n, std::string name);

#endif