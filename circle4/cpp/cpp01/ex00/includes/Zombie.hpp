#ifndef Zombie_HPP
#define Zombie_HPP

#include <iostream>
#include <string>
class Zombie {
  private:
    std::string name;

  public:
    std::string getZombieName();
    void announce(void);
    void randomChump(std::string name);
    Zombie *newZombie(std::string name);

    Zombie();
    Zombie::Zombie(std::string);
    ~Zombie();
};

#endif