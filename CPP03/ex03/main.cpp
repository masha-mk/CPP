#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "        CLAPTRAP TESTS" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        // Test 1: Constructors and assignment
        std::cout << "--- Constructors & Assignment ---" << std::endl;
        
        ClapTrap a;   //Default         
        ClapTrap b(a);     // Copy 
        ClapTrap c("Alice");    //Parameterized
        
        b = c;    // Copy Assignment operator          
        
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
    }

    std::cout << "\n========================================" << std::endl;
    std::cout << "        SCAVTRAP TESTS" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        // Test 1: Constructors show inheritance order
        std::cout << "--- Constructors (ClapTrap -> ScavTrap) ---" << std::endl;
        ScavTrap a;              // Default
        ScavTrap b(a);           // Copy
        ScavTrap c("Alice");     // Parameterized
        std::cout << std::endl;

        // Test 2: Assignment operator
        std::cout << "--- Assignment Operator ---" << std::endl;
        a = b;
        std::cout << std::endl;

        // Test 3: ScavTrap attack (different message from ClapTrap)
        std::cout << "--- Attack Test (ScavTrap specific message) ---" << std::endl;
        b.attack("target");
        c.attack("target");
        a.attack("target");
        std::cout << std::endl;

        // Test 4: Guard Gate (ScavTrap specific function)
        std::cout << "--- Guard Gate (ScavTrap special ability) ---" << std::endl;
        a.guardGate();
        b.guardGate();
        std::cout << std::endl;

        // Test 5: Taking damage (inherited function)
        std::cout << "--- Taking Damage Test ---" << std::endl;
        b.takeDamage(20);
        b.takeDamage(40);
        std::cout << std::endl;

        // Test 6: Energy depletion (50 attacks)
        std::cout << "--- Energy Test (50 attacks should deplete) ---" << std::endl;
        for (int i = 0; i < 50; i++)
            b.attack("enemy");
        std::cout << std::endl;

        // Test 7: Repair with no energy
        std::cout << "--- Repair Test (should fail, no energy) ---" << std::endl;
        b.beRepaired(30);
        std::cout << std::endl;

        std::cout << "--- ScavTrap Destructors (ScavTrap -> ClapTrap) ---" << std::endl;
    }
    std::cout << "\n========================================" << std::endl;
    std::cout << "        FRAGTRAP TESTS" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
                // Test 1: Constructors show inheritance order
        std::cout << "--- Constructors (ClapTrap -> FragTrap) ---" << std::endl;
        FragTrap a;              // Default
        FragTrap b(a);           // Copy
        FragTrap c("Alice");     // Parameterized
        std::cout << std::endl;

        // Test 2: Assignment operator
        std::cout << "--- Assignment Operator ---" << std::endl;
        a = b;
        std::cout << std::endl;

        // Test 3: FragTrap attack (different message from ClapTrap)
        std::cout << "--- Attack Test (FragTrap specific message) ---" << std::endl;
        b.attack("target");
        c.attack("target");
        a.attack("target");
        std::cout << std::endl;

        // Test 4: High Five (FragTrap specific function)
        std::cout << "--- Guard Gate (FragTrap special ability) ---" << std::endl;
        a.highFivesGuys();
        b.highFivesGuys();
        std::cout << std::endl;

        // Test 5: Taking damage (inherited function)
        std::cout << "--- Taking Damage Test ---" << std::endl;
        b.takeDamage(20);
        b.takeDamage(40);
        std::cout << std::endl;

        // Test 6: Energy depletion (100 attacks)
        std::cout << "--- Energy Test (100 attacks should deplete) ---" << std::endl;
        for (int i = 0; i < 100; i++)
            b.attack("enemy");
        std::cout << std::endl;

        // Test 7: Repair with no energy
        std::cout << "--- Repair Test (should fail, no energy) ---" << std::endl;
        b.beRepaired(30);
        std::cout << std::endl;

        std::cout << "--- FragTrap Destructors (FragTrap -> ClapTrap) ---" << std::endl;
    }
    return (0);
}