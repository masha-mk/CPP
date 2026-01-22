#include "Fixed.hpp"

Fixed::Fixed(void): a(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other): a(other.a)
{
    std::cout << "Copy constructor called" << std::endl;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

 Fixed& Fixed::operator=(const Fixed& other)
{
    std::cout << "Copy assignment operator called" << std::endl;
    // Verifier que l adresse de l objet courant(this) n est pas egale à l adresse de other
    if (this != &other)
    {
        //Copier la valeur de l attribut a de l objet other dans l attribut a
        //de l objet courant.
        this->a = other.a;
    }
    return (*this);
}

int Fixed::getRawBits(void)const
{
    std::cout << "getRawBits member function called" << std::endl;
    return (this->a);
}

void Fixed::setRawBits(int const raw)
{
    std::cout << "setRawBits member function called" << std::endl;
    //modifier la valeur de l attribut a
    this->a = raw;
}

