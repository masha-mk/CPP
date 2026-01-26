#include "ClapTrap.hpp"

int main (void)
{
    ClapTrap a;
    ClapTrap b(a);
    ClapTrap c;

    c = b;
    a.attack("b");
    b.takeDamage(3);
    b.takeDamage(7);
    b.takeDamage(7);
    b.beRepaired(5);
    b.attack("a");
    a.takeDamage(3);
    a.beRepaired(5);

    return (0);
}