#include <vector>
#include <deque>
#include "easyfind.hpp"


int main()
{
    std::cout << "======test sur vector======" << std::endl;
    std::vector<int> vect;
    for(int i(0); i < 10; i++)
        vect.push_back(i);
    try 
    {
        std::cout << "index found: " << easyfind(vect, 4) << std::endl;
        std::cout << "index found: " << easyfind(vect, 20) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }

    std::cout << "========test sur deque=======" << std::endl;
    std::deque<int> nums;
    nums.push_back(1);
    nums.push_back(5);
    nums.push_back(10);
    nums.push_back(16);
    nums.push_front(10);
    nums.push_front(5);
    try 
    {
        std::cout << "index found of 5: " << easyfind(nums, 5) << std::endl;
        std::cout << "index found of 20: " << easyfind(nums, 20) << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    return 0;
}