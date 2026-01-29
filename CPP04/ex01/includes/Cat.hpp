#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat: public Animal
{
    private:
        Brain *brain;
    public: 
        Cat();
        Cat(const Cat& other);
        ~Cat();
        Cat& operator=(const Cat& other);

        void setIdea(int index, std::string const &idea);
        std::string getIdea(int index) const;
        void makeSound() const;
};


#endif