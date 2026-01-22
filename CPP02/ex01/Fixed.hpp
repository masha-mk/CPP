#include <iostream>
#include <cmath>

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
        std::ostream& operator<<(std::ostream& out, const Fixed& fixed);

        Fixed(const int value);
        Fixed(const float nb);
         
        // Destructeur
        ~Fixed();
        
        int getRawBits(void) const;
        void setRawBits(int const raw);
        int toInt(void) const;
        int toFloat(void) const;
};