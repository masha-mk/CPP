#include "Fixed.hpp"

int main( void ) 
{
    //Default constructor called
    Fixed a;
    //Int constructor called
    Fixed const b( 10 ); 
    //Float constructor called
    Fixed const c( 42.42f );
    //Copy constructor called
    Fixed const d( b );
    //Copy assignment operator called
    //Float constructor called
    //Copy assignment operator called
    a = Fixed( 1234.4321f ); //a = objet temporaire
    
    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;
    
    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer" << std::endl;
    return 0;
}

