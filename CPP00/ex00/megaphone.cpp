#include <iostream>
#include <cctype>

/*
std -> namespace of the standard library
:: -> "into"
std::cout-> cout into std
<< -> stream insertion  
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
        for (int j = 0; argv[i][j]; j++)
            std::cout << (unsigned char)toupper(argv[i][j]);
        if (i < argc - 1)
            std::cout << " ";
    }
    std::cout << std::endl;
    return (0);
}
