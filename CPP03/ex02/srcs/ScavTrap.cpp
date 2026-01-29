#include "ScavTrap.hpp"

ScavTrap::ScavTrap() // : ClapTrap() - appelle le constructeur par devfaut
{
    hitPoints = 100;
    energy = 50;
    attackDamage = 20;
    std::cout << "ScavTrap default constructor called" << std::endl;
}

/*
: ClapTrap(name) -> appelle le constructeur ClapTrap et nitialise avec les valeurs de base du constructeur ClapTrap
Dans le corps de la fonction, on change les valeurs
*/
ScavTrap::ScavTrap(const std::string &name): ClapTrap(name)
{
    hitPoints = 100;
    energy = 50;
    attackDamage = 20;
    std::cout << "Parameterized ScavTrap " << name << " constructor called" << std::endl;
}
/*
: ClapTrap(name) -> copie les nouvelles valeurs (appelle ClapTrap(const ClapTrap& other))
*/
ScavTrap::ScavTrap(const ScavTrap& other): ClapTrap(other)
{
     std::cout << "ScavTrap copy constructor called" << std::endl;
}

ScavTrap::~ScavTrap()
{
    std::cout << "ScavTrap destructor called" << std::endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& other)
{
    std::cout << "Copy assignment operator called(ScavTrap)" << std::endl;
    if (this != &other)
        ClapTrap::operator=(other); // Appelle l opérateur de la classe de base
    return (*this);
}


void ScavTrap::attack(const std::string &target)
{
    if (hitPoints <= 0 || energy <= 0)
    {
        std::cout << "ScavTrap " << name << " can't attack: not enough energy or hit points" << std::endl;
        return;
    }
    else
    {
        energy -= 1;
        std::cout << "ScavTrap " << name << " attacks " << target 
                  << ", causing " << attackDamage << " points of damage! (HP: " << hitPoints << ", Energy: " << energy << ")" << std::endl;
    }
    
}


void ScavTrap::guardGate(void)
{
    std::cout << "ScavTrap " << name << " is now in Gate keeper mode" << std::endl;
}