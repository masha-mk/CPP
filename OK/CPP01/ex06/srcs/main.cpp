#include "Harl.hpp"


int main(int argc, char **argv)
{
    Harl harl;
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR" };
    int levelIndex = -1;

    if (argc != 2)
    {
        std::cerr << "Usage: ./harl <argument>" << std::endl;
        return (1);
    }

    for (int i = 0; i < 4; i++)
    {
        if (levels[i] == std::string(argv[1]))
        {
            levelIndex = i;
            break;
        }
    }
    //fall though -commentaire ppur le compilateur de passer au suivant
    switch (levelIndex)
    {
        case 0:
            std::cout << "[ DEBUG ]" << std::endl;
            harl.complain("DEBUG");
            /* fall through */ 
        case 1:
            std::cout << "[ INFO ]" << std::endl;
            harl.complain("INFO");
            /* fall through */
        case 2:
            std::cout << "[ WARNING ]" << std::endl;
            harl.complain("WARNING");
            /* fall through */
        case 3:
            std::cout << "[ ERROR ]" << std::endl;
            harl.complain("ERROR");
            break;
        default:
            std::cout << "Probably complaining about insignificant problems" << std::endl;
    }
    return (0);
}