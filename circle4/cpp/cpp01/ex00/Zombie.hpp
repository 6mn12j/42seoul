#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {
  private:
    std::string name;

  public:
    std::string getZombieName();
    void announce(void);

    Zombie();
    Zombie(std::string);
    ~Zombie();
};

void randomChump(std::string name);
Zombie *newZombie(std::string name);
#endif