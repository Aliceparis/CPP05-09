#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <exception>

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
        void    setGrade(unsigned int grade);
        std::string getName() const;
        unsigned int getGrade() const;
        void    increment_grade();
        void    decrement_grade();

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