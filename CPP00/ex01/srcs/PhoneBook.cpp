#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>

// If the string is to long, we take only 10 first carracters and we add "."
std::string truncate(std::string str)
{
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

//Constructeur
PhoneBook::PhoneBook()
{
    this->_index = 0;
    this->_total = 0;
}

//Destructeur
PhoneBook::~PhoneBook()
{
}


void PhoneBook::addContact(void)
{
    //Declare std::input for stocking user's input
    //Declare newContact object (temp)
    std::string input;
    Contact newContact;

    //Ask user for each element
    std::cout << "First name: "; //Affiche le texte sur l'ecran
    std::getline(std::cin, input); //Lire une ligne tapée par user (stdin)
    newContact.setFirstName(input); //Assigne la valeur input au _firstName via une fonction.

    std::cout <<"Last name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout <<"Nickname: ";
    std::getline(std::cin, input);
    newContact.setNickName(input);

    std::cout <<"Phone number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);  

    std::cout <<"Darkest secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    //Assign values from temp object to permanent array of private class
    this->_contacts[this->_index] = newContact;

    //Incriment index (circular)
    this->_index = (this->_index + 1) % 8;

    //Incriment total until its 8
    if (this->_total < 8)
        this->_total++;
}
/*
Display all contacts
setw(10) -> " book" 10 chars and if the word is 
shorter than 10, it completes with " " on the left until
the total is equal to 10. 
setw is equal to: printf("%10s", "Maria") in C.
*/
void PhoneBook::print_Contacts(void)
{
    std::cout << "      index|first name | last name|nickname" << std::endl;
    for (int i = 0; i < this->_total; i++)
    {
        Contact c = this->_contacts[i];

        std::cout << std::setw(10) << i << "|";
        std::cout << std::setw(10) << truncate(c.getFirstName()) << "|";
        std::cout << std::setw(10) << truncate(c.getLastName()) << "|";
        std::cout << std::setw(10) << truncate(c.getNickName()) << std::endl;
    }
}
/*
We print the PhoneBook
After we ask to user the index he needs with getline
We convert it to int
We check if it is ok
Declare object Contact c for the shorter writing
We print all information needed
*/
void PhoneBook::searchContact(void)
{
    int index;
    std::string input;

    if (this->_total == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        return;
    }
    //Appeler la methode d une classe depuis une autre methode
    this->print_Contacts();
    std::cout << "Enter index: ";
    std::getline(std::cin, input);
    index = std::atoi(input.c_str()); //c_str->convert en const *char

    if (index < 0 || index >= this->_total)
    {
        std::cout << "Invalid index" << std::endl;
        return;
    }
    Contact c = this->_contacts[index];
    std::cout << "First name: " << c.getFirstName() << std::endl;
    std::cout << "Last name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;
}



