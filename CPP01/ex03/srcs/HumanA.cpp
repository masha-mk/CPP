#include "HumanA.hpp"

HumanA::HumanA(const std::string& name, Weapon &weapon): weapon(weapon), name(name)
{
}

void HumanA::attack(void)const
{
    std::cout << this->name << " attacks with their " << weapon.getType() << std::endl;
}

