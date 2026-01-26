#include "ClapTrap.hpp"

int main (void)
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "        CLAPTRAP TESTS" << std::endl;
    std::cout << "========================================\n" << std::endl;
        // Test 1: Constructors and assignment
        std::cout << "--- Constructors & Assignment ---" << std::endl;
        
        ClapTrap a;   //default         
        ClapTrap b(a);     // by copy 
        ClapTrap c("Alice");    //parameterized
        
        b = c;    // Copysignment operator          
        
        std::cout << std::endl;

        // Test 2: Energy depletion (10 attacks)
        std::cout << "--- Energy Test (11 attacks, should fail on last) ---" << std::endl;
        for (int i = 0; i < 11; i++)
            a.attack("enemy");
        std::cout << std::endl;

        // Test 3: Taking damage and attacking while damaged
        std::cout << "--- Damage & Attack Test ---" << std::endl;
        c.takeDamage(3);
        c.takeDamage(5);
        c.attack("someone");
        c.beRepaired(10);
        std::cout << std::endl;

        std::cout << "--- ClapTrap Destructors ---" << std::endl;


    return (0);
}