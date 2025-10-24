#include "Herite.hpp"
#include <cstdlib>

Base*   generate(void)
{
    if (std::rand() % 3 == 0)
        return new A;   
    else if (std::rand() % 3 == 1)
        return new B;
    else
        return new C;
}

void    identify(Base*  p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "It is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "It is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "It is C" << std::endl;
    else
        std::cout << "It is unkown type" << std::endl;
}

void    identify(Base&  p)
{
    try 
    {
        (void)dynamic_cast<A&>(p);
        std::cout << "This is reference A" << std::endl;
    }
    catch (std::exception &e)
    {
        try 
        {
            (void)dynamic_cast<B&>(p);
            std::cout << "This is reference B" << std::endl;
        }
        catch(std::exception &e)
        {
            try
            {
                (void)dynamic_cast<C&>(p);
                std::cout << "This is reference C" << std::endl;
            }
            catch(std::exception &e)
            {
                std::cout << "Error: unkown type" << std::endl;
            }
        }
    }
}
