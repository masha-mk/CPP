#include "Dog.hpp"
#include "Brain.hpp"


Dog::Dog(): Animal("Dog")
{
     this->brain = new Brain();
     std::cout << "Dog constructor called" << std::endl;
}

Dog::Dog(const Dog& other): Animal(other)
{
    this->brain = new Brain(*other.brain);
    std::cout << "Dog copy constructor called" << std::endl;
}

void Dog::setIdea(int index, std::string const &idea)
{
    this->brain->setIdea(idea, index);
}

std::string Dog::getIdea(int index) const
{
    return (this->brain->getIdea(index));
}

Dog::~Dog()
{
    delete(this->brain);
    std::cout << "Dog destructor called" << std::endl;
}

Dog& Dog::operator=(const Dog& other)
{
    std::cout << "Dog copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain;
    }
    return (*this);
}

void Dog::makeSound() const
{
    std::cout << "Wooof woof!" << std::endl;
}