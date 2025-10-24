#include "ScalarConverter.hpp"
#include <string>


int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "error: must have one input" << std::endl;
        return 1;
    }
    std::string input(av[1]);
    if (input.empty())
    {
        std::cout << "Error: must have one input" << std::endl;
        return 1;
    }
    ScalarConverter::converte(input);
    return 0;
}