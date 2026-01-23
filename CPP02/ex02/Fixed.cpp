#include "Fixed.hpp"

/* -----------Constructeurs / Destructeurs-------------*/

Fixed::Fixed(void): a(0)
{
    //std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
{
    //std::cout << "Copy constructor called" << std::endl;
    this->a = other.a; 
}


//Constructeur qui transforme un nombre normal en fixed point avec un int en paramètre
// 00000000 00001010 << 8 bits (10)
// 00001010 00000000 
//bit 9 et 11 sont égaux à 11 donc 2^11 + 2^9 = 2048 + 512 = 2560
Fixed::Fixed(const int value)
{
    //std::cout << "Int constructor called" << std::endl;
    this->a = value << fractionalBits; // value * 256 (2^8)
}

//Constructeur qui transforme un nombre normal en fixed point avec un float en paramètre
// on arrondit le resultat de nb * 256 
Fixed::Fixed(const float nb)
{
    //std::cout << "Float constructor called" << std::endl;
    this->a = static_cast <int>(roundf(nb * (1<<fractionalBits)));
}



Fixed::~Fixed(void)
{
    //std::cout << "Destructor called" << std::endl;
}


/*------------Opérateurs-------------------*/

Fixed& Fixed::operator=(const Fixed& other)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    // Verifier que l adresse de l objet courant(this) n est pas egale à l adresse de other
    if (this != &other)
    {
        //Copier la valeur de l attribut a de l objet other dans l attribut a
        //de l objet courant.
        this->a = other.a;
    }
    return (*this);
}
        
        // Opérateurs de comparaison
bool Fixed::operator>(const Fixed& other) const
{
    return (this->a > other.a);
}
bool Fixed::operator<(const Fixed& other) const
{
    return (this->a < other.a);
}
bool Fixed::operator>=(const Fixed& other) const
{
    return (this->a >= other.a);
}
bool Fixed::operator<=(const Fixed& other) const
{
    return (this->a <= other.a);
}
bool Fixed::operator==(const Fixed& other) const
{
    return (this->a == other.a);
}
bool Fixed::operator!=(const Fixed& other) const
{
    return (this->a != other.a);
}


        // Operateurs arithmetiques
Fixed Fixed::operator+(const Fixed& other) const
{
    Fixed res;

    res.setRawBits(this->a + other.a);
    return (res);
}
Fixed Fixed::operator-(const Fixed& other) const
{
    Fixed res;

    res.setRawBits(this->a - other.a); 
    return (res);
}
Fixed Fixed::operator*(const Fixed& other) const
{
    Fixed res;

    res.setRawBits((this->a * other.a) >> fractionalBits);
    return (res);
}
Fixed Fixed::operator/(const Fixed& other) const
{
    Fixed res;

    res.setRawBits((this->a << fractionalBits) / other.a);
    return (res);
}

        // Opérateurs d'incrimentation et décrimentation (epsilon)

Fixed& Fixed::operator++()
{
    this->a++; //modifie l objet actuel
    return (*this);  //retourne l objet lui meme
}

Fixed Fixed::operator++(int)
{
    Fixed temp = *this; //copier l ancienne valeur
    this->a++; //modifier l objet actuel
    return (temp); 
}


Fixed& Fixed::operator--()
{
    this->a--; //modifie l objet actuel
    return (*this);  //retourne l objet lui meme
}

Fixed Fixed::operator--(int)
{
    Fixed temp = *this; //copier l ancienne valeur
    this->a--; //modifier l objet actuel
    return (temp); 
}

/*---------------Getter et setteur------------------*/
int Fixed::getRawBits(void)const
{
    //std::cout << "getRawBits member function called" << std::endl;
    return (this->a);
}

void Fixed::setRawBits(int const raw)
{
    //std::cout << "setRawBits member function called" << std::endl;
    //modifier la valeur de l attribut a
    this->a = raw;
}


Fixed& Fixed::min(Fixed& a, Fixed& b)
{
    if (a > b)
        return (b);
    else
        return (a);
}
const Fixed& Fixed::min(const Fixed& a, const Fixed &b)
{
    if (a > b)
        return (b);
    else
        return (a);    
}
Fixed& Fixed::max(Fixed& a, Fixed& b)
{
    if (a > b)
        return (a);
    else
        return (b);
}
const Fixed& Fixed::max(const Fixed& a, const Fixed &b)
{
    if (a > b)
        return (a);
    else
        return (b);
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
// On modifie out passer en ref et on retourne un nouveau resultat.
std::ostream& operator<<(std::ostream& out, const Fixed& fixed)
{
    out << fixed.toFloat();
    return (out);
}
