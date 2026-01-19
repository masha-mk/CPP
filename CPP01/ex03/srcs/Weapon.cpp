#include "Weapon.hpp"

Weapon::Weapon(const std::string& type): type(type)
{
}

//Permettre de donner l acces aux armes aux autres classes.
const std::string& Weapon::getType(void) const
{
    return (this->type);
}


 void  Weapon::setType(const std::string& type)
 {
    this->type = type;
 }