#include "Animal.hpp"

Animal::Animal(): type("default")
{
    std::cout << "Default constructor called" << std::endl;
}

Animal::Animal(const std::string &type): type(type)
{
     std::cout << "Parameterized constructor called" << std::endl;
}
Animal::Animal(const Animal& other): type(other.type)
{
     std::cout << "Copy constructor called" << std::endl;
}

Animal:: ~Animal()
{
     std::cout << "Destructor called" << std::endl;
}

std::string Animal::getType()const
{
    return (type);
}

Animal& Animal::operator=(const Animal& other)
{
    std::cout << "Animal copy assignment operator called" << std::endl;
    if (this != &other)
        type = other.type;
    return (*this);
}

void Animal::makeSound() const
{
    std::cout << "Animal sound..." << std::endl;
}