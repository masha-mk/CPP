#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    std::cout << "\n========================================" << std::endl;
    std::cout << "        CAT / DOG TESTS" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        std::cout << "\n--- Simple tests ---\n" << std::endl;
        
        //Default constructor called
        const Animal* meta = new Animal();
        
        // Animal pointe sur l objet Dog.
        // Parameterized constructor called (Dog constructor appelle Animal("Dog"))
        // Dog constructor called
        const Animal* j = new Dog();
        
        // Parameterized constructor called (Cat constructor appelle Animal("Dog"))
        // Cat constructor called
        const Animal* i = new Cat();
        
        //Dog
        std::cout << j->getType() << " " << std::endl;
        //Cat
        std::cout << i->getType() << " " << std::endl;
        // Cat sound
        i->makeSound(); //will output the cat sound!
        // Dog sound
        j->makeSound();
        // Animal sound...
        meta->makeSound();

        delete meta;
        delete j;
        delete i;

        std::cout << "\n--- Loop tests ---\n" << std::endl;

        Animal* animals[4];
        animals[0] = new Dog();
        animals[1] = new Cat();
        animals[2] = new Dog();
        animals[3] = new Cat();

        for (int i = 0; i < 4; i++)
            animals[i]->makeSound(); 
        for (int i = 0; i < 4; i++)
            delete animals[i];
    }
    std::cout << "\n========================================" << std::endl;
    std::cout << "        WRONG_CAT / WRONG_DOG TESTS" << std::endl;
    std::cout << "========================================\n" << std::endl;
    {
        const WrongAnimal* wrongMeta = new WrongAnimal();
        const WrongAnimal* wrongCat = new WrongCat();

        const WrongCat* newWrong = new WrongCat();

        std::cout << wrongCat->getType() << std::endl;

        wrongMeta->makeSound();
        //Appelle WrongAnimal donc la meme fonction que wrongMeta
        wrongCat->makeSound();
        newWrong->makeSound();


        delete wrongMeta;
        delete wrongCat;
        delete newWrong;
    }
    return 0;
}   