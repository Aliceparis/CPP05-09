#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

class   Span
{
    private:
        unsigned int    _max_size;
        std::vector<int>  _nbr;
    public:
        Span();
        Span(unsigned int N);
        Span(const Span &other);
        Span&   operator=(const Span &other);
        ~Span();

        /*membre fonction*/
        void    addNumber(int m);
        int shortestSpan() const;
        int longestSpan() const;

        template<typename iterator>
        void    add_range_number(iterator begin, iterator end)
        {
            size_t count = std::distance(begin, end);
            if (_nbr.size() + count > _max_size)
                throw std::out_of_range("container will be full");
            _nbr.insert(_nbr.end(), begin, end);
        };
        /*debug*/
        typedef std::vector<int>::iterator iterator;
        typedef std::vector<int>::const_iterator const_iterator;
        iterator begin(){ return _nbr.begin();};
        iterator end() { return _nbr.end();};

        const_iterator begin() const { return _nbr.begin();};
        const_iterator end() const { return _nbr.end();}; 
        unsigned int    getsize() const;
        void    display() const;
};


#endif