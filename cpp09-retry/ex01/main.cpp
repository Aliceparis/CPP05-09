#include "RPN.hpp"

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: must have one argument" << std::endl;
        return 1;
    }
    Rpn inverse;
    try 
    {
        inverse.load_info(av[1]);
        //inverse.display();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}