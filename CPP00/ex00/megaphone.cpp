#include <iostream>
#include <cctype>

/*
std -> namespace of the standard library
:: -> "into"
std::cout-> cout into std
<< -> stream insertion  

declare std::string type
str.length -> function (method) that take length's variable
from string class.
*/
int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
        return (0);
    }
    for (int i = 1; i < argc; i++)
    {
        std::string str(argv[i]);
        for (size_t j = 0; j < str.length(); j++)
            str[j] = std::toupper(str[j]);
        std::cout << str;
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
