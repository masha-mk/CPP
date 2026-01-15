#include "Zombie.hpp"

void randomChump( std::string name );
Zombie* newZombie( std::string name );

int main (void)
{
    std::cout << "Test stack: " << std::endl;
    randomChump("Bob");
    std::cout << "--------------------------" << std::endl;

    Zombie *heap_Zombie;
    std::cout << "Test heap: " << std::endl;
    heap_Zombie = newZombie("Alice");
    heap_Zombie->announce();
    delete heap_Zombie;

    return (0);
}