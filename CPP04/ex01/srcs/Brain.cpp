#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "Brain copy constructor called" << std::endl;
    for (int i = 0; i < 100; i++)
        ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
    std::cout << "Brain destructor called" << std::endl;
}


Brain& Brain::operator=(const Brain& other)
{
    std::cout << "Brain copy assignment operator called" << std::endl;
    if (this != &other)
    {
        for (int i = 0; i < 100; i++)
            this->ideas[i] = other.ideas[i];
    }
    return (*this);
}

 std::string const& Brain::getIdea(int const &index) const
 {
    if (index >= 0 && index < 100)
        return (this->ideas[index]);
     return (this->ideas[0]);
 }


void Brain::setIdea(std::string const &idea, int const &index)
{
    if (index >= 0 && index < 100)
        this->ideas[index] = idea;
}


