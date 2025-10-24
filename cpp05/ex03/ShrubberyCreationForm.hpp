#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class   Bureaucrat;
class   AForm;

class   ShrubberyCreationForm: public AForm
{
    private:
        std::string _target;
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const std::string &target);
        ShrubberyCreationForm(const ShrubberyCreationForm &other);
        ShrubberyCreationForm&  operator=(const ShrubberyCreationForm &other);
        ~ShrubberyCreationForm();

        /*membre fonction*/
        void    execute_action() const;
};



#endif