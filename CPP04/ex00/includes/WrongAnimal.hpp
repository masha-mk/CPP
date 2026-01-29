#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
    protected :
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal& other);
        ~WrongAnimal();

        std::string getType() const;

        WrongAnimal& operator=(const WrongAnimal&other);
        void makeSound() const;
};

#endif
