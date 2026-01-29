#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>


class Animal
{
    protected : 
        std::string type;
    public:
        Animal();
        Animal(const std::string &type);
        Animal(const Animal& other);
        // Trouve un bon destructeur selon le type réel de l objet
        virtual ~Animal();

        std::string getType() const;

        Animal& operator=(const Animal&other);
        // Appelle une bonne fonction selon le type(Dog ou Cat)
        virtual void makeSound() const;
};





#endif