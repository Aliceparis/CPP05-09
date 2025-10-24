#include "Span.hpp"
#include <limits>
#include <algorithm>

Span::Span(): _max_size(0){};

Span::Span(unsigned int N): _max_size(N){};

Span::Span(const Span &other): _max_size(other._max_size), _nbr(other._nbr){};

Span&   Span::operator=(const Span &other)
{
    if (this != &other)
    {
        _max_size = other._max_size;
        _nbr = other._nbr;
    }
    return *this;
};
Span::~Span(){};

/*membre fonction*/
void    Span::addNumber(int m)
{
    if (_nbr.size() >= _max_size)
        throw std::out_of_range("container is full");
    _nbr.push_back(m);
}
int Span::shortestSpan() const
{
    if (_nbr.size() < 2)
        throw std::out_of_range("container has not enough numbers");
    std::vector<int> copy = _nbr;
    std::sort(copy.begin(), copy.end());
    int minispan = std::numeric_limits<int>::max();
    for(size_t i(1); i < copy.size(); i++)
    {
        int diff = copy[i] - copy[i - 1];
        if (diff < minispan)
            minispan = diff;
    }
    return minispan;
}

int Span::longestSpan() const
{
    if (_nbr.size() < 2)
        throw std::out_of_range("container has not enough numbers");
    int max_span = *std::max_element(_nbr.begin(), _nbr.end());
    int min_span = *std::min_element(_nbr.begin(), _nbr.end());

    return (max_span - min_span);
}
/*debug*/
unsigned int    Span::getsize() const
{
    return _nbr.size();
}
void    Span::display() const
{
    std::cout << "Container size: " << this->getsize() 
        << ", max size: " << this->_max_size << ", Numbers in container: "; 
    for(Span::const_iterator it = this->begin(); it != this->end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}