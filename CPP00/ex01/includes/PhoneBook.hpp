#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <Contact.hpp>

class PhoneBook
{
    private:
        Contact _contacts[8]; //Array of 8 contacts
        int _index; //current index
        int _total; //total number of contacts
        
        void print_Contacts(); // for Printing
    public:
        PhoneBook(); //constructeur
        ~PhoneBook(); //destructeur

        void addContact(); //ADD
        void searchContact(); // SEARCH
};


#endif