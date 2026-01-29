#include "ClapTrap.hpp"

// Default Constructor
ClapTrap::ClapTrap(): name("Bob"), hitPoints(10), energy(10), attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

// Parameterized constructor
ClapTrap::ClapTrap(const std::string& name): name(name), hitPoints(10), energy(10), attackDamage(0)
{
    std::cout << "Parameterized " << name <<  " constructor called" << std::endl;
}



// Copy constructor
ClapTrap::ClapTrap(const ClapTrap& other): 
                            name(other.name), hitPoints(other.hitPoints),
                            energy(other.energy), attackDamage(other.attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}



// Destructor
ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}



//Utilisation si l objet existe deja pour assigner
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    if (this != &other)
    {
        name = other.name;
        hitPoints = other.hitPoints;
        energy = other.energy;
        attackDamage = other.attackDamage;
    }
    return (*this);
}


void ClapTrap::attack(const std::string& target)
{
    if (hitPoints <= 0 || energy <= 0)
    {
        std::cout << "ClapTrap " << name << " can't attack: not enough energy or hit points" << std::endl;
        return;
    }
    else
    {
        energy -= 1;
        std::cout << "ClapTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage! (HP: " << hitPoints << ", Energy: " << energy << ")" << std::endl;
    }
    
}


void ClapTrap::takeDamage(unsigned int amount)
{
    if (hitPoints <= 0)
    {
        std::cout << "ClapTrap " << name << " is already destroyed" << std::endl;
        return;
    }
    if (amount >= static_cast<unsigned int>(hitPoints))
        hitPoints = 0;
    else
        hitPoints -= static_cast<int>(amount);
    
    std::cout << "ClapTrap " << name << " takes " << amount
              << " points of damage! (HP: " << hitPoints << ")" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0 || energy <= 0)
    {
         std::cout << "ClapTrap " << name << " can't be repaired: not enough energy" << std::endl;
         return;
    }
    energy -= 1;
    hitPoints += amount;
    std::cout << "ClapTrap " << name << " repaired itself for " << amount 
          << " hit points (HP: " << hitPoints << ", Energy: " << energy << ")" << std::endl;
}