#include "PhoneBook.hpp"
#include <string>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <cctype>


bool isWhitespace(std::string str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isspace(str[i]))
            return (false);
    }
    return (true);
}

std::string sanitize(std::string s)
{
    for (size_t i = 0; i < s.size(); i++)
    {
        unsigned char c = static_cast<unsigned char>(s[i]);
        if (std::iscntrl(c)) //detecte le caractère de contrôle
            s[i] = ' ';
    }
    return (s);
}

// If the string is to long, we take only 10 first carracters and we add "."
std::string truncate(std::string str)
{
    str = sanitize(str);
    if (str.length() > 10)
        return (str.substr(0, 9) + ".");
    return (str);
}

//Constructeur
PhoneBook::PhoneBook() : _index(0), _total(0)
{
}

//Destructeur
PhoneBook::~PhoneBook()
{
}

bool PhoneBook::addContact(void)
{
    //Declare std::input for stocking user's input
    //Declare newContact object (temp)
    std::string input;
    Contact newContact;

/*----------------First Name--------------------------*/
    std::cout << "First name: "; 
    if (!std::getline(std::cin, input)) 
        return (false);
    while (input.empty() || isWhitespace(input))
    {
        std::cout << "Field can't be empty. First name: ";
        if (!std::getline(std::cin, input))
            return (false);
    }
    newContact.setFirstName(input); //Assigne la valeur input au _firstName via une fonction.

/*----------------Last Name--------------------------*/
    std::cout <<"Last name: ";
    if (!std::getline(std::cin, input))
        return (false);
    while (input.empty() || isWhitespace(input))
    {
        std::cout << "Field can't be empty. Last name: ";
        if (!std::getline(std::cin, input))
            return (false);
    }
    newContact.setLastName(input);

/*----------------Nickname--------------------------*/
    std::cout <<"Nickname: ";
    if (!std::getline(std::cin, input))
        return (false);
    while (input.empty() || isWhitespace(input))
    {
        std::cout << "Field can't be empty. Nickname: ";
        if (!std::getline(std::cin, input))
            return (false);
    }
    newContact.setNickName(input);

/*----------------Phone nb--------------------------*/
    std::cout <<"Phone number: ";
    if (!std::getline(std::cin, input))
        return (false);
    while (input.empty() || isWhitespace(input))
    {
        std::cout << "Field can't be empty. Phone number: ";
        if (!std::getline(std::cin, input))
            return (false);
    }
    newContact.setPhoneNumber(input);  

/*----------------Darkest secret--------------------------*/
    std::cout <<"Darkest secret: ";
    if (!std::getline(std::cin, input))
        return (false);
    while (input.empty() || isWhitespace(input))
    {
        std::cout << "Field can't be empty. Darkest secret: ";
        if (!std::getline(std::cin, input))
            return (false);
    }
    newContact.setDarkestSecret(input);

    //Assign values from temp object to permanent array of private class
    this->_contacts[this->_index] = newContact;

    //Incriment index (circular)
    this->_index = (this->_index + 1) % 8;

    //Incriment total until it is 8
    if (this->_total < 8)
        this->_total++;
    return (true);
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
    std::cout << "      index|first name|last name|nickname" << std::endl;
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
false = EOF (Ctrl + D)
*/
bool PhoneBook::searchContact(void)
{
    int index;
    std::string input;

    if (this->_total == 0)
    {
        std::cout << "PhoneBook is empty" << std::endl;
        return (true);
    }

    //Appeler la methode d une classe depuis une autre methode (this)
    this->print_Contacts();

    //Check if the index is empty or its not a number
    std::cout << "Enter index: ";
    if (!std::getline(std::cin, input))
        return (false);
    if (input.empty())
    {
        std::cout << "Invalid index" << std::endl;
        return (true);
    }

    for (size_t i = 0; i < input.length(); i++)
    {
        if (!std::isdigit(input[i]))
        {
            std::cout << "Invalid index" << std::endl;
            return (true);
        }
    }
    index = std::atoi(input.c_str()); //c_str->convert en const *char

    if (index < 0 || index >= this->_total)
    {
        std::cout << "Invalid index" << std::endl;
        return (true);
    }
    // Declare c for make it shorter
    Contact c = this->_contacts[index];

    //Display information of corresponding contact
    std::cout << "First name: " << c.getFirstName() << std::endl;
    std::cout << "Last name: " << c.getLastName() << std::endl;
    std::cout << "Nickname: " << c.getNickName() << std::endl;
    std::cout << "Phone number: " << c.getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << c.getDarkestSecret() << std::endl;

    return (true);
}



