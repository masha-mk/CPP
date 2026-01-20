#include <iostream>
#include <string>
#include <fstream> 

int main(int argc, char **argv)
{
    if (argc != 4)
    {
        std::cerr << "Usage: ./a.out <filename> <String 1> <String 2>" << std::endl;
        return (1);
    }
    else
    {
        std::string filename = argv[1];
        std::string s1 = argv[2];
        std::string s2 = argv[3];
        std::string line;
        
        //classe pour lire des fichiers (input file stream)
        std::ifstream inputFile(filename.c_str());
        //classe pour ecrire des fichiers (output file stream)
        std::ofstream outputFile((filename + ".replace").c_str());

        if (!inputFile.is_open())
        {
            std::cerr << "Error: Could not open file" << std::endl;
            return (1);
        }
        if (!outputFile.is_open())
        {
            std::cerr << "Error: Failed to open input file" << std::endl;
            return (1);
        }
        while (std::getline(inputFile, line))
        {
            size_t pos = 0;

            while ((pos = line.find(s1, pos)) != std::string::npos) 
            {
                line.erase(pos, s1.length());
                line.insert(pos, s2);
                pos += s2.length();
            }
            outputFile << line << std::endl;
        }
        
    }
    return (0);
}