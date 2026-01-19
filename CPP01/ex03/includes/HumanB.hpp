#ifndef HUMANB_HPP
#define HUMANB_HPP

#endif

#include "Weapon.hpp"

class HumanB
{
    private:
        Weapon* weapon;
        std::string name;
    public:
        HumanB(std::string name);
        void attack(void)const;
        void setWeapon(Weapon& weapon);
};