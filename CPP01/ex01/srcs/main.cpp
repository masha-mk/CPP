#include "Zombie.hpp"

int main(void)
{
    int N = 70;
    Zombie *newZombie = zombieHorde(N, "zombie");
    for (int i = 0; i < N; i++ )
    {
        std::cout << "Zombie " << (i + 1) << ": ";
        newZombie[i].announce();
    }
    delete[] newZombie;
    return (0);
}