#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name(""), hitPoints(10), energy(10), attackDamage(0)
{
    std::cout << "Default constructor called" << std::endl;
}

ClapTrap::ClapTrap(std::string& name): name(name), hitPoints(10), energy(10), attackDamage(0)
{
    std::cout << "Parameterized constructor called" << std::endl;
}
// Cree un nouveau objet a partir d un autre
ClapTrap::ClapTrap(const ClapTrap& other): 
                            name(other.name), hitPoints(other.hitPoints),
                            energy(other.energy), attackDamage(other.attackDamage)
{
    std::cout << "Copy constructor called" << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "Destructor called" << std::endl;
}

//Utilisation si l objet existe deja
ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
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
        std::cout << "ClapTrap" << name << " can't attack: not enough energy or hit points" << std::endl;
        return;
    }
    else
    {
        energy -= 1;
        std::cout << "ClapTrap " << name << "attacks " << target 
                  << ", causing " << attackDamage << " points of damage!" << std::endl;
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
              << " points of danage! (HP: " << hitPoints << ")" << std::endl;

}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (hitPoints <= 0 || energy <= 0)
        std::cout << "ClapTrap" << name << " can't be repaired: not enough energy" << std::endl;

    energy -= 1;
    hitPoints += amount;
    if (hitPoints > 10)
        hitPoints = 10;
    std::cout << "ClapTrap " << name << " repaired itself for " << amount << " hit points (HP: "
              << hitPoints << ", Energy: " << energy << ")" << std::endl;
}