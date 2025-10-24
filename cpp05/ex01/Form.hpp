#ifndef FORM_HPP
# define FORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class   Bureaucrat;
class   Form
{
    private:
        const std::string   _name;
        bool    _is_signed;
        const unsigned int  _grade_to_signe;
        const unsigned int  _grade_to_execute;
    public:
        Form();
        Form(const std::string& name, unsigned int sign, unsigned int execute);
        Form(const Form& other);
        Form&   operator=(const Form& other);
        ~Form();

        /*getter*/
        std::string getName() const;
        bool    get_is_signed() const;
        unsigned int    get_grade_signe() const;
        unsigned int    get_grade_execute() const;

        /*membre fonction*/
        void    beSigned(const Bureaucrat& bureau);

        /*error*/
        class   GradeTooHighException: public std::exception
        {
            private:
                virtual const char* what() const throw()
                {
                    return ("Form: grade is too high");
                }
        };
        class    GradeTooLowException: public std::exception
        {
            private:
                virtual const char* what() const throw()
                {
                    return ("Form: grade is too low");
                }
        };
};

std::ostream&   operator<<(std::ostream& out, const Form& form);


#endif