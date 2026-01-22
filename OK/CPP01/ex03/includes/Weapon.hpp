#ifndef WEAPON_HPP
#define WEAPON_HPP

#include <iostream>


class Weapon
{
    private:
        std::string type;
    public:
        //constructeur
        Weapon(const std::string& type); 
        //getter
        const std::string& getType(void) const;
        //setter
        void setType(const std::string& type);
};



#endif