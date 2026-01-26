#include "Fixed.hpp"


Fixed::Fixed(void): a(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = other; // appelle opérateur = pour l affichage mais c mieux this->a = other.a
}


//Constructeur qui transforme le nombre en fixed point avec un int en paramètre
// 00000000 00001010 << 8 bits (10)
// 00001010 00000000 
//bit 9 et 11 sont égaux à 11 donc 2^11 + 2^9 = 2048 + 512 = 2560

Fixed::Fixed(const int value)
{
    std::cout << "Int constructor called" << std::endl;
    this->a = value << fractionalBits; // value * 256 (2^8)
}

//Constructeur qui transforme le normal en fixed point avec un float en paramètre
// On decale 1 de 8 bit et puis on multiplie le float (l inverse impossible)
// on arrondit le resultat de nb * 256 

Fixed::Fixed(const float nb)
{
    std::cout << "Float constructor called" << std::endl;
    this->a = static_cast <int>(roundf(nb * (1 << fractionalBits))); // 1 << 8 = 256
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
    //modifier la valeur de l attribut privé
    this->a = raw;
}


int Fixed::toInt(void) const
{
    return (this->a >> fractionalBits); // a / 256
}

float Fixed::toFloat(void) const
{
    return (static_cast<float>(this->a) / (1 << fractionalBits));
}
// ecrire std::cout << fixed au lieu de std::cout << fixed.toFloat()
// On modifie out passé en ref et on retourne un nouveau resultat.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}

