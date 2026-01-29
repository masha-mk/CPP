#include "Cat.hpp"
#include "Brain.hpp"

Cat::Cat(): Animal("Cat")
{
     this->brain = new Brain();
     std::cout << "Cat constructor called" << std::endl;
}

Cat::Cat(const Cat& other): Animal(other)
{
    //deep copy -> copie independante (pas un brain pour 2)
    this->brain = new Brain(*other.brain);
    std::cout << "Cat copy constructor called" << std::endl;
}

void Cat::setIdea(int index, std::string const &idea)
{
    this->brain->setIdea(idea, index);
}

std::string Cat::getIdea(int index) const
{
    return (this->brain->getIdea(index));
}

Cat::~Cat()
{
    delete(this->brain);
    std::cout << "Cat destructor called" << std::endl;
}

Cat& Cat::operator=(const Cat& other)
{
    std::cout << "Cat copy assignment operator called" << std::endl;
    if (this != &other)
    {
        Animal::operator=(other);
        *brain = *other.brain; //deep copie (contenu de a dans b)
    }
    return (*this);
}

void Cat::makeSound() const
{
    std::cout << "Meooooowww" << std::endl;
}