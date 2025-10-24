#ifndef AFORM_HPP
#define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>
#include <exception>

class   Bureaucrat;

class   AForm
{
    protected:
        const std::string  _name;
        const int   _grade_to_sign;
        const int   _grade_to_execute;
        bool    _is_signed;
    public:
        AForm(const std::string& name, int sign_grade, int execute_grade);
        AForm(const AForm& other);
        AForm&  operator=(const AForm& other);
        virtual ~AForm();

        /*error*/
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("AForm: grade is too low");
                }
        };
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("AForm: grade is too high");
                }
        };
        class IsNotSigned: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("AForm: is not signed");
                }
        };

        /*getter*/
        std::string getName() const;
        int get_sign_grade() const;
        int get_execute_grade() const;
        bool    get_is_signed() const;

        /*membre fonction*/
        void    beSigned(const Bureaucrat& bureau);
        void    execute(const Bureaucrat& executor) const;
        virtual void    execute_action() const = 0;
        
};

std::ostream&   operator<<(std::ostream& out, const AForm& formule);
#endif