#include "Base.hpp"
#include "Herite.hpp"
#include <ctime>
#include <cstdlib>

int main(void)
{
    std::srand(time(0));
    Base*   random = generate();

    std::cout << "\nIdentify from pointer: \n";
    identify(random);
    std::cout << "\nIdentify from reference: \n";
    identify(*random);

    delete random;
    return (0);
}
