#include <PhoneBook.hpp>
#include <string>
#include <iostream>

//Constructeur
PhoneBook::PhoneBook()
{
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

void PhoneBook::searchContact(void)
{
    
}



