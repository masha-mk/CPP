#include "Fixed.hpp"

int main( void ) 
{

    std::cout << "[ 42 tests ]" << std::endl;
    std::cout << "\n";
    {
        Fixed a;
        Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
        std::cout << a << std::endl;
        std::cout << ++a << std::endl;
        std::cout << a << std::endl;
        std::cout << a++ << std::endl;
        std::cout << a << std::endl;
        std::cout << b << std::endl;
        std::cout << Fixed::max( a, b ) << std::endl;

    }
    std::cout << "\n";
    std::cout << "[ Opérateurs de comparaisons ]" << std::endl;
    std::cout << "\n";
    {
        Fixed a(5);
        Fixed b (10);
        Fixed c(5);

        // 0: false,  1: true
        std::cout << "a >  b: " << (a > b) << std::endl; 
        std::cout << "a <  b: " << (a < b) << std::endl;
        std::cout << "a >= b: " << (a >= c) << std::endl;
        std::cout << "a <= b: " << (a <= b) << std::endl;
        std::cout << "a == b: " << (a == c) << std::endl;
        std::cout << "a != b: " << (a != b) << std::endl;

    }
    std::cout << "\n";
    std::cout << "[ Opérateurs arithmétiques ]" << std::endl;
    std::cout << "\n";
    {
        Fixed a(10);
        Fixed b (2);
        Fixed c(3.5f);

        std::cout << "a + b: " << (a + b) << std::endl; 
        std::cout << "a - b: " << (a - b) << std::endl;  
        std::cout << "a * b: " << (a * b) << std::endl; 
        std::cout << "a / b: " << (a / b) << std::endl;  
        std::cout << "c * c: " << (c * c) << std::endl;   
    }
 
    std::cout << "\n";
    std::cout << "[ Incrimentation / Decrementation ]" << std::endl;
    std::cout << "\n";
    {
            Fixed a(5);

        std::cout << "a: " << a << std::endl;       
        std::cout << "++a: " << ++a << std::endl;    
        std::cout << "a: " << a << std::endl;        
        std::cout << "a++: " << a++ << std::endl;    
        std::cout << "a: " << a << std::endl;       

        std::cout << "--a: " << --a << std::endl;   
        std::cout << "a--: " << a-- << std::endl;    
        std::cout << "a: " << a << std::endl;
    }

    std::cout << "\n";
    std::cout << "[ Min et Max ]" << std::endl;
    std::cout << "\n";

    Fixed a(42.42f);
    Fixed b(21.21f);
    {
        std::cout << "min(a, b): " << Fixed::min(a, b) << std::endl;
        std::cout << "max(a, b): " << Fixed::max(a, b) << std::endl;

    }
    std::cout << "\n";
    std::cout << "[ Multiple operations ]" << std::endl;
    std::cout << "\n";
    {
        Fixed a(10);
        Fixed b(3);
        Fixed result;

        result = ((a + b) * Fixed(2)) / Fixed(4);
        std::cout << "((10 + 3) * 2) / 4 = " << result << std::endl;

        Fixed c = Fixed(5.05f) * Fixed(2);
        std::cout << "5.05 * 2 = " << c << std::endl; 
    }

    return (0);
}

