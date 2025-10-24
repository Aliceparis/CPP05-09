#ifndef HERITE_HPP
#define HERITE_HPP

#include <iostream>
#include "Base.hpp"

class Base;
class   A: public Base{
};

class   B: public Base{
};

class   C: public Base{
};

Base*   generate(void);
void    identify(Base*  p);
void    identify(Base&  p);



#endif