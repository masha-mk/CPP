#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main (void)
{
    PhoneBook phonebook;
    std::string cmd;

    while (1)
    {
        std::cout << "Enter cmd (ADD / SEARCH / EXIT): ";
        //Si la lecture de l entrée standard a échoué, break
        if (!std::getline(std::cin, cmd))
        {
            std::cout << std::endl << "exit" << std::endl;
            break;
        }
        if (cmd == "EXIT")
        {
            std::cout << "exit" <<std::endl;
            break;
        }
        else if (cmd == "ADD")
        {
            if (phonebook.addContact() != true)
            {
                std::cout << std::endl << "exit" <<std::endl;
                break;
            }
        }
        else if (cmd == "SEARCH")
        {
            if (phonebook.searchContact() != true)
            {
                std::cout << std::endl << "exit" <<std::endl;
                break;
            }
        }
        else
            std::cout << "Invalid command" << std::endl;
    }
    return (0);
}