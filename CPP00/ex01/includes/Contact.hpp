#ifndef CONTACT_HPP
#define CONTACT_HPP


#include <string>

// std:: -> Appartient a la bibliotheque standard
class Contact
{
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickName;
        std::string _phoneNumber;
        std::string _darkestSecret; 
    public:
        Contact(); //Constructeur
        ~Contact(); //Destructeur

        //Getters - reading values 
        //Const for not being able to modify values in the getter
        std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickName() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;

        //Setters - for modify values
        void setFirstName(std::string firstName);
        void setLastName(std::string lastName);
        void setNickName(std::string nickName);
        void setPhoneNumber(std::string phoneNumber);
        void setDarkestSecret(std::string darkestSecret);
};

#endif