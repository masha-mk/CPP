#include "DiamondTrap.hpp"

/*
DiamonTrap herite de FragTrap et ScavTrap, donc on appelle 3 constructeurs
*/
DiamondTrap::DiamondTrap(): ClapTrap("default_clap_name"), FragTrap(), ScavTrap(),name("default")
{ 
    this->attackDamage = 30;
    std::cout << "DiamondTrap default constructor called" << std::endl;
}


DiamondTrap::DiamondTrap(const std::string& name):
                            ClapTrap(name + "_clap_name"),  FragTrap(), 
                            ScavTrap(), name(name)
{
    this->attackDamage = 30;    // FragTrap
    std::cout << "Parameterized DiamondTrap " << name << " constructor called" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& other):
                                ClapTrap(other), FragTrap(other),
                                ScavTrap(other), name(other.name)
{
     std::cout << "DiamondTrap copy constructor called" << std::endl;
}

 DiamondTrap::~DiamondTrap()
 {
        std::cout << "DiamondTrap destructor called" << std::endl;
 }


DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    std::cout << "Copy assignment operator called DiamondTrap" << std::endl;
    if (this != &other)
    {
        ClapTrap::operator=(other);
        name = other.name;
    }
    return (*this);
}

 void DiamondTrap::whoAmI(void)
 {
    std::cout << "ClapTrap's name: " << ClapTrap::name
    << " and DiamondTrap's name is " << this->name << std::endl;
 }