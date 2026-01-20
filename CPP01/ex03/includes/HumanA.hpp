#ifndef HUMANA_HPP
#define HUMANA_HPP

#include "Weapon.hpp"

//HumanA a toujours une arme dès la création de l objet donc pas null donc reference
class HumanA
{
    private:
    //Reference vers un objet de type Weapon
        Weapon& weapon;
        std::string name;
    public:
    //constructeur
        HumanA(const std::string& name, Weapon &weapon);
    //methode de la classe attack
        void attack(void)const;
};

#endif