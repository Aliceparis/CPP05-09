#include "PmergeMe.hpp"
#include <ctime>

int main(int ac, char **av)
{
    PmergeMe    pm;

    try 
    {
        int resultat = pm.parse(ac, av);
        if (resultat != -1)
        {
            std::cout << "Before: ";
            pm.print_vect();
            std::cout << "After: ";

            /*time for vector*/
            std::clock_t    start_vect = std::clock();
            pm.sort_vect();
            std::clock_t    end_vect = std::clock();
            /*time for deque*/
            std::clock_t    start_deq = std::clock();
            pm.sort_deq();
            std::clock_t    end_deq = std::clock();

            double  time_vect = static_cast<double>(end_vect - start_vect);
            double  time_deque = 1000000.0 * (end_deq - start_deq) / CLOCKS_PER_SEC;

            std::cout << "Time to process a range of " << pm.get_vect().size()
                 << " elements with std::vector: " << time_vect << " us" << std::endl;
            std::cout << "Time to process a range of " << pm.get_deque().size()
                 << " elements with std::deque: " << time_deque << " us" << std::endl;
        }
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}