#ifndef HUMANA_HPP
#define HUMANA_HPP

#endif
#include "Weapon.hpp"

//HumanA a toujours une arme dès la création de l objet
class HumanA
{
    private:
        Weapon& weapon;
        std::string name;
    public:
        HumanA(const std::string name, Weapon &weapon);
        void attack(void)const;
};