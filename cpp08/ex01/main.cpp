#include "Span.hpp"
#include <iostream>

void    print_header(const std::string &input)
{
    std::cout << "\n=========================" << std::endl;
    std::cout << input << std::endl;
    std::cout << "===========================" << std::endl;
}

void    test_small_size(Span &sp)
{
    try 
    {
        print_header("Test1: test small size");
        sp.addNumber(10);
        sp.display();
        std::cout << "largest in sp: " << sp.longestSpan() << std::endl;
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
void    test_full_size(Span &sp)
{
    try 
    {
        print_header("Test2: test full size");
        sp.addNumber(10);
        sp.addNumber(5);
        sp.addNumber(1);
        sp.display();
        sp.addNumber(11);
    }
    catch(std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
void    test_array_number(Span &sp)
{
    try 
    {
        print_header("Test3:array number");
        std::vector<int> numbers;
        for(int i(0); i < 10; i++)
            numbers.push_back(i * 2);
        sp.add_range_number(numbers.begin(), numbers.end());
        sp.display();
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
}
int main()
{
    Span    sp(3);
    Span    sp2(100);

    test_small_size(sp);
    test_full_size(sp);
    test_array_number(sp2);
    return 0;
}