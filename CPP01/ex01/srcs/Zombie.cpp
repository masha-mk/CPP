#include "Zombie.hpp"

//Ici le constructeur est par defaut car on appelle un setter par la suite.(pour plusieurs zombies)
Zombie::Zombie()
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

void Zombie::setName(std::string n)
{
    this->name = n;
}