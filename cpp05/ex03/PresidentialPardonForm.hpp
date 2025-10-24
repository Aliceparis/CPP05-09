#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"
#include "Bureaucrat.hpp"

class   Bureaucrat;
class   AForm;

class   PresidentialPardonForm: public AForm
{
    private:
        std::string _target;
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const std::string &target);
        PresidentialPardonForm(const PresidentialPardonForm &other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm &other);
        ~PresidentialPardonForm();

        /*membre fonction*/
        void    execute_action() const;
};


#endif