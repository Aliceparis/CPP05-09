#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <exception>
#include <stack>

class   Rpn
{
    private:
        std::stack<int> _data;
        bool    is_number(const std::string &token, long &resultat) const;
        bool    is_operator(const std::string &token) const;
        void    calcule(const std::string &input);
    public:
        Rpn();
        Rpn(const Rpn &other);
        Rpn&    operator=(const Rpn &other);
        ~Rpn();

        void    load_info(const std::string &input);
        void    processe(const std::string   &input);
        
        /*debug*/
        void    display();
};

#endif