#include <iostream>

/*Fixed point est une façon de stocjer des nombres avec des 
decimale en utilisant un int en mémoire.

Il faut choisir un nombre de bits réservés à la partie
décimale. Ici c est 8 derniers (sur 32 habituellement)

3.5
3.5 * (2^8) = 896   (2^8 = 256)
raw = 896 (on stock dans la memoire) 
L idée c est etre plus précis, ne pas avoir d arrondis bizarres
qui peuvent flouter les calculs.
       [entier] [fraction]
896 = 00000011 10000000 
        3 bits  128 bits = 128/256 = 0.5
*/

class Fixed
{
    private:
        int a;
        static const int fractionalBits = 8;
    public:
        // Constructeur par defaut (consruit l objet de base)
        Fixed();
        // La copie de constructeur (creer un nouveau objet à partir d'un autre objet existant)
        Fixed(const Fixed& other);
        // Remplacer le contenu de la copie du constructeur par le premier (other)
        Fixed& operator=(const Fixed& other);
        // Destructeur
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
};