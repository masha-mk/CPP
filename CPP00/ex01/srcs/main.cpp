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
        std::getline(std::cin, cmd);

        if (cmd == "EXIT")
            break;
        else if (cmd == "ADD")
            phonebook.addContact();
        else if (cmd == "SEARCH")
            phonebook.searchContact();
        else
            std::cout << "Invalid command" << std::endl;
    }
    std::cout << "exit" <<std::endl;
    return (0);
}