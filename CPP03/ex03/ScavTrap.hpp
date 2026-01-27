#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "ClapTrap.hpp"

//ScavTrap hérite de Clavtrap, donc il a accès a ses attributs protected ou publics.
class ScavTrap : virtual public ClapTrap
{
    public:
        ScavTrap();
        ScavTrap(const std::string& name);
        ScavTrap(const ScavTrap& other);
        ~ScavTrap();

        ScavTrap& operator=(const ScavTrap& other);
        
        void attack(const std::string &target);
        void guardGate();
};

#endif