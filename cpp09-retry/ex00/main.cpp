#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cout << "Error: must have one argument" << std::endl;
        return 1;
    }
    BitcoinExchange exchange;
    try 
    {
        exchange.load_database("data.csv");
        exchange.process_exchange(av[1]);

    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
        return 1;
    }
    return 0;
}