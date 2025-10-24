#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <exception>
#include <algorithm>

template<typename T>
int easyfind(T &container, int n)
{
    typename T::iterator it = std::find(container.begin(), container.end(), n);

    if (it == container.end())
        throw std::out_of_range("not find the value");
    return std::distance(container.begin(), it);
};

#endif