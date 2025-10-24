#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   Bureaucrat;
class   AForm;

class RobotomyRequestForm: public AForm
{
    private:
        std::string _target;
    public:
        RobotomyRequestForm();
        RobotomyRequestForm(const std::string &target);
        RobotomyRequestForm(const RobotomyRequestForm &other);
        RobotomyRequestForm&    operator=(const RobotomyRequestForm &other);
        ~RobotomyRequestForm();

        /*membre fonction*/
        void    execute_action() const;
};

#endif