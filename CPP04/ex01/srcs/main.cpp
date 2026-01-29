#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"


int main()
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "        CAT / DOG TESTS" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        Animal* animals[10];

        for (int i = 0; i < 5; i++)
            animals[i] = new Dog();
        
        for (int i = 5; i < 10; i++)
            animals[i] = new Cat();
        
        for (int i = 0; i < 10; i++)
            delete animals[i];
        
    }
    std::cout << "\n========================================" << std::endl;
    std::cout << "        DEEP COPY TEST" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        Dog original;
        original.setIdea(0, "J'ai faim");

        Dog copy(original); // Deep copy

        std::cout << "Original: " << original.getIdea(0) << std::endl;
        std::cout << "Copy: " << copy.getIdea(0) << std::endl;

        //Modifier l'original
        original.setIdea(0, "Je veux dormir");

        //Si c est deep copy: Copy affiche toujours "j'ai faim"
        //Si c est shallow copy : Copy affiche "je veux dormir" -> pas bon

        std::cout << "\nApres modification:" << std::endl;
        std::cout << "Original: " << original.getIdea(0) << std::endl;
        std::cout << "Copy: " << copy.getIdea(0) << std::endl;

    }
    std::cout << "\n========================================" << std::endl;
    std::cout << "        OPERATOR= TEST" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        Dog a;
        Dog b;

        a.setIdea(0, "J'ai faim");
        b.setIdea(0, "J'ai soif");
        std::cout << "Avant operator=:" << std::endl;
        std::cout << "A: " << a.getIdea(0) << std::endl;
        std::cout << "B: " << b.getIdea(0) << std::endl;

        b = a;
        std::cout << "\n\nApres b = a:" << std::endl;
        std::cout << "A: " << a.getIdea(0) << std::endl;
        std::cout << "B: " << b.getIdea(0) << std::endl;

        a.setIdea(0, "Idee modifiee");
        std::cout << "\nApres modification de A:" << std::endl;
        std::cout << "A: " << a.getIdea(0) << std::endl;
        std::cout << "B: " << b.getIdea(0) << std::endl;
    }
    std::cout << "\n========================================" << std::endl;
    std::cout << "        MAKESOUND TEST" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        const Animal* dog = new Dog();
        const Animal* cat = new Cat();
    
        dog->makeSound();  // Doit faire "Wooof woof!"
        cat->makeSound();  // Doit faire "Meooooowww"
    
        delete dog;
        delete cat;
    }
    std::cout << "\n========================================" << std::endl;
    std::cout << "        SCOPE TEST (tmp before basic)" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        Dog basic;
        basic.setIdea(0, "Idea");
        {
            Dog tmp = basic;  // Deep copy
            std::cout << "tmp idea: " << tmp.getIdea(0) << std::endl;
        }  // tmp détruit ici - si shallow copy, le Brain de basic est delete!
    }
    return 0;
}   