#include "Bureaucrat.hpp"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

Bureaucrat::Bureaucrat(): _name(""), _grade(150)
{
    std::cout << GREEN << "Bureaucrat: Default constructor called" << RESET << std::endl;
}
Bureaucrat::Bureaucrat(const std::string& name, unsigned int grade): _name(name)
{
    std::cout << GREEN << "Bureaucrat: Param constructor called" << RESET << std::endl;
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other):_name(other._name), _grade(other._grade)
{
    std::cout << GREEN << "Bureaucrat: Copy constructor called" << RESET << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << GREEN << "Bureaucrat: assignment operator called" << RESET << std::endl;
    if (this != &other)
        _grade = other._grade;
    return (*this);
}
Bureaucrat::~Bureaucrat()
{
    std::cout << GREEN << "Bureaucrat: destructor called " << this->_name << RESET << std::endl;
}

/*membre fonction*/
std::string Bureaucrat::getName() const
{
    return (this->_name);
}
unsigned int Bureaucrat::getGrade() const
{
    return (this->_grade);
}
void    Bureaucrat::setgrade(unsigned int grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}
void    Bureaucrat::increment_grade()
{
    try 
    {
        unsigned int    tmp(this->_grade);
        setgrade(tmp + 1);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    Bureaucrat::decrement_grade()
{
    try 
    {
        unsigned int    tmp(this->_grade);
        setgrade(tmp - 1);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}

void    Bureaucrat::signForm(AForm& aform) const
{
    try
    {
        if (this->getGrade() <= aform.get_grade_signe())
        {
            aform.besigned(*this);
            std::cout << this->_name << " signed " << aform.getName() << std::endl;
        }
        else
            throw AForm::GradeTooLowException();
    }
    catch(std::exception& e)
    {  
        std::cerr << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(const AForm& form) const
{
    try 
    {
        form.execute(*this);
        std::cout << this->_name << " executed " << form.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cerr << "Execution failed because " << e.what() << std::endl;
    }
}

std::ostream&   operator<<(std::ostream& out, const Bureaucrat& bureau)
{
    out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << std::endl;
    return (out);
}