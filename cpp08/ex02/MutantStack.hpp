#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <iterator>
#include <deque>

template<typename T>
class MutantStack: public std::stack<T>
{
    private:

    public:
        MutantStack();
        MutantStack(const MutantStack &other);
        MutantStack&    operator=(const MutantStack &other);
        ~MutantStack();

        /*membre fonction*/
        typedef typename std::stack<T>::container_type::iterator iterator;
        typedef typename std::stack<T>::container_type::const_iterator const_iterator;

        iterator begin(){ return this->c.begin();};
        iterator end() { return this->c.end();};
        const_iterator begin() const { return this->c.begin();};
        const_iterator end() const {return this->c.end();};
        
};

/*debug*/
template<typename T>
std::ostream&   operator<<(std::ostream &out, const MutantStack<T> &ms)
{
    out << "Mutantstack with size: " << ms.size() << ", value in the container: ";
    for(typename MutantStack<T>::const_iterator it = ms.begin(); it != ms.end(); it++)
        out << *it << " ";
    return out;
}
#endif