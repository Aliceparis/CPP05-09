#include "iter.hpp"
#include <iostream>
/*fonction for debug*/
template<typename T>
void    print_array(const T &array, size_t len, const std::string &str)
{
    std::cout << str << ":";
    for(size_t i(0); i < len; i++)
        std::cout << array[i] << " ";
    std::cout << std::endl;
}
/*fonction with non const argument*/
template<typename T>
void    increment(T &n)
{
    n++;
}
/*fonction with const argument*/
template<typename T>
void    print_element(const T &n)
{
    std::cout << n << " ";
}
void    test_array_int()
{
    int array[] = {1, 5, 10, 19};
    const int *const a2 = array;
    size_t  len = sizeof(array) / sizeof(array[0]);

    std::cout << "========test int========" << std::endl;
    print_array(array, len, "original ");
    iter(array, len, print_element<int>);
    std::cout << std::endl;
    iter(array, len, increment<int>);
    print_array(array, len, "after increment ");

    iter(a2, len, print_element<int>);
}

template<typename T>
void    touppercase(T &c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 'a' + 'A';
}
void    test_array_char()
{
    char    array[] = {'a', 'b', 'c', 'd'};
    size_t   len = sizeof(array) / sizeof(array[0]);

    std::cout << "========test char=======" << std::endl;
    print_array(array, len, "original");
    iter(array, len, print_element<char>);
    std::cout << std::endl;
    iter(array, len, touppercase<char>);
    print_array(array, len, "after");

}

int main(void)
{
    test_array_int();
    test_array_char();
}