#include "HumanB.hpp"

HumanB::HumanB(std::string name): weapon(NULL), name(name)
{
}

void HumanB::attack(void)const
{
    if (!this->weapon)
        std::cout << this->name << " attacks unarmed" << std::endl;
    else
        std::cout << this->name << " attacks with their " << weapon->getType() << std::endl;
}

  void HumanB::setWeapon(Weapon& weapon)
  {
    this->weapon = &weapon;
  }

