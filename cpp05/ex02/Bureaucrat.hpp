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
        unsigned int    _grade;
    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, unsigned int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        /*membre fonction*/
        std::string getName() const;
        unsigned int getGrade() const;
        void    setgrade(unsigned int grade);
        void    increment_grade();
        void    decrement_grade();
        void    signForm(AForm& aform) const;
        void    executeForm(const AForm& form) const;
        
        /*error*/
        class   GradeTooHighException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return("Bureaucrat: grade is too high");
                }
        };
        class   GradeTooLowException: public std::exception
        {
            public:
                virtual const char* what() const throw()
                {
                    return ("Bureaucrat: grade is too low");
                }
        };
};

std::ostream&     operator<<(std::ostream& out, const Bureaucrat& bureau);


#endif