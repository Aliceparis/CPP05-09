#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "AForm.hpp"

class   AForm;

class   Bureaucrat
{
    private:
        const std::string   _name;
        int _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        /*error*/
        class GradeTooHighException: public std::exception
        {
            public:
                virtual const char*  what() const throw()
                {
                    return ("grade is too high");
                }
        };
        class GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("grade is too low");
                }
        };

        /*membre fonction*/
        std::string getName() const;
        int getGrade() const;
        void    setgrade(int grade);
        void    increment_grade();
        void    decrement_grade();
        void    signForm(AForm& formule) const;
        void    executeForm(AForm const &form) const;

};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bureau);
#endif