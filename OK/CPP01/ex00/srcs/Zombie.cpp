#include "Zombie.hpp"

// Ici on utilise un constructeur avec paramètre car on veut créer un seul zombie
Zombie::Zombie(std::string name):name(name)
{
}

Zombie::~Zombie()
{
    std::cout << "Zombie " << this->name << " destroyed" << std::endl;
}

void Zombie::announce(void)
{
    std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}