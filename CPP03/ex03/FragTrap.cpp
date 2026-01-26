#include "FragTrap.hpp"

FragTrap::FragTrap() // : ClapTrap() - appelle le constructeur par devfaut
{
    hitPoints = 100;
    energy = 100;
    attackDamage = 30;
    std::cout << "FragTrap default constructor called" << std::endl;
}

/*
: ClapTrap(name) -> appelle le constructeur ClapTrap et nitialise avec les valeurs de base du constructeur ClapTrap
Dans le corps de la fonction, on change les valeurs
*/

FragTrap::FragTrap(const std::string name): ClapTrap(name)
{
    hitPoints = 100;
    energy = 100;
    attackDamage = 30;
     std::cout << "Parameterized FragTrap " << name << " constructor called" << std::endl;
}

FragTrap::FragTrap(const FragTrap& other): ClapTrap(other)
{
     std::cout << "FragTrap copy constructor called" << std::endl;
}

FragTrap::~FragTrap()
{
     std::cout << "FragTrap destructor called" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other)
{
    std::cout << "Copy assignment operator called (FragTrap)" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other);
    return (*this);
}

void FragTrap::attack(const std::string &target)
{
    if (hitPoints <= 0 || energy <= 0)
    {
        std::cout << "FragTrap " << name << " can't attack: not enough energy or hit points" << std::endl;
        return;
    }
    else
    {
        energy -= 1;
        std::cout << "FragTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage! (HP: " << hitPoints << ", Energy: " << energy << ")" << std::endl;
    }
    
}

void FragTrap::highFivesGuys(void)
{
    std::cout << "FragTrap " << name << " requests a high five!" << std::endl;
}