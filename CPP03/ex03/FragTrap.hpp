#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

//virtual = FragTrap et ScavTrap n appellent pas ClapTrap car virtual
// FragTrap et les autres partagent la meme copie de ClapTrap (une seule instance)
class FragTrap : virtual public ClapTrap
{
    public: 
        FragTrap();
        FragTrap(const std::string& name);
        FragTrap(const FragTrap& other);
        ~FragTrap();

        FragTrap& operator=(const FragTrap& other);

        void attack(const std::string &target);
        void highFivesGuys(void);
};

#endif