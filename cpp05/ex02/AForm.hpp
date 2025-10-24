#ifndef AFORM_HPP
# define AFORM_HPP

#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class   Bureaucrat;

class   AForm
{
    protected:
        const unsigned int  _grade_signe;
        const unsigned int  _grade_execute;
        const std::string   _name;
        bool    _is_signed;
    public:
        AForm(const std::string& name, unsigned int sign, unsigned int execute);
        AForm(const AForm& other);
        AForm&  operator=(const AForm& other);
        virtual ~AForm();

        /*getter*/
        std::string getName() const;
        unsigned int    get_grade_signe() const;
        unsigned int    get_grade_execute() const;
        bool    get_is_signed() const;

        /*membre fonction*/
         void    besigned(const Bureaucrat& bureau);
         void    execute(const Bureaucrat& executor) const;
        virtual void    execute_action() const = 0;
        /*error*/
        class   GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("AForm: grade is too high");
                }
        };
        class   GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("AForm: grade is too low");
                }
        };
        class   FormNotSigned: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Form is not signed");
                }
        };
};

std::ostream&   operator<<(std::ostream& out, const AForm& aform);

#endif