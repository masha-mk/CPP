#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"

//Human B peut ne pas avoir d arme. Donc ici on utilise un pointeur
class HumanB
{
    private:
        Weapon* weapon;
        std::string name;
    public:
    //constructeur
        HumanB(const std::string& name);
    //methode de classe attack
        void attack(void)const;
    //setter car peut etre changé
        void setWeapon(Weapon& weapon);
};

#endif