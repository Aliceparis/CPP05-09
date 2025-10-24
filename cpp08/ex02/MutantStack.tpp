#include "MutantStack.hpp"

template<typename T>
MutantStack<T>::MutantStack(){
};

template<typename T>
MutantStack<T>::MutantStack(const MutantStack &other): std::stack<T>(other){
};

template<typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &other)
{
    if (this != &other)
        this->c = other.c;
    return *this;
}

template<typename T>
MutantStack<T>::~MutantStack(){};