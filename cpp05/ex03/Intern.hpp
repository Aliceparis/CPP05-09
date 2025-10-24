#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"

class   AForm;
class   Intern
{
    private:
        AForm*   make_shrubbery(const std::string &target);
        AForm*   make_robot(const std::string &target);
        AForm*   make_president(const std::string &target);
    public:
        Intern();
        Intern(const Intern &other);
        Intern& operator=(const Intern &other);
        ~Intern();

        /*membre fonction*/
        AForm*    makeForm(const std::string &name, const std::string &target);

};


#endif