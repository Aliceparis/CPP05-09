#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>
#include "Form.hpp"

class Form;

class   Bureaucrat
{
    private:
        const std::string   _name;
        unsigned int    _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, unsigned int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        /*getter setter*/
        void    setGrade(unsigned int grade);
        std::string getName() const;
        unsigned int getGrade() const;

        /*membre fonction*/
        void    increment_grade();
        void    decrement_grade();
        void    signForm(Form& form) const;

        /*error*/
        class   GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: grade is too high");
                }
        };
        class   GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Error: grade is too low");
                }
        };
};

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bureau);


#endif