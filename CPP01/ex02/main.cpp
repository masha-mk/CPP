#include <iostream>

/*
Pointeur = variable qui contnent une addresse de la variable sur laquelle
elle pointe
Reference: un alias d'une variable existante
La reference ne peut pas etre nulle, a la meme cible (const), 
*/
int main(void)
{
    std::string string = "HI THIS IS BRAIN";
    std::string* stringPTR = &string;
    std::string& stringREF = string;

    std::cout << "Memory address of the string: " << &string << std::endl;
    std::cout << "Memory address of the stringPTR: " << stringPTR << std::endl;
    std::cout << "Memory address of the stringREF: " << &stringREF << std::endl;

    std::cout << "\n";

    std::cout << "The value of the string: " << string << std::endl;
    std::cout << "The value of the stringPTR: " << *stringPTR << std::endl;
    std::cout << "The value of the stringREF: " <<stringREF << std::endl;

}