#include "Bureaucrat.hpp"
#define YELLOW  "\033[33m"
#define RESET   "\33[0m"

Bureaucrat::Bureaucrat(): _name(""), _grade(150)
{
    std::cout << YELLOW << "Bureaucrat: Default constructor called" << RESET << std::endl;
}
Bureaucrat::Bureaucrat(const std::string& name, int grade): _name(name)
{
    std::cout << YELLOW << "Bureaucrat: Param constructor called" << RESET << std::endl;
    if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (grade > 150)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}
Bureaucrat::Bureaucrat(const Bureaucrat& other): _name(other._name), _grade(other._grade)
{
    std::cout << YELLOW << "Bureaucrat: Copy constructor called" << RESET << std::endl;
}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
    std::cout << YELLOW << "Bureaucrat: assignment operator called" << RESET << std::endl;
    if (this != &other)
        _grade = other._grade;
    return *this;
}
Bureaucrat::~Bureaucrat()
{
    std::cout << YELLOW << "Bureaucrat: destructor called" << RESET << std::endl;
}

/*membre fonction*/
std::string Bureaucrat::getName() const
{
    return this->_name;
}
int Bureaucrat::getGrade() const
{
    return _grade;
}
void    Bureaucrat::setgrade(int grade)
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
        int tmp(this->_grade);
        setgrade(tmp + 1);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    Bureaucrat::decrement_grade()
{
    try 
    {
        int tmp(this->_grade);
        setgrade(tmp - 1);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    Bureaucrat::signForm(AForm& formule) const
{
    try 
    {
        formule.beSigned(*this);
        std::cout << this->_name << " signed " << formule.getName() << std::endl;
    }
    catch(std::exception& e)
    {
        std::cout << this->_name << " couldn't sign " << formule.getName()
            << " because " << e.what() << std::endl;
    }
}
void    Bureaucrat::executeForm(const AForm &form) const
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
    out << YELLOW << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << RESET << std::endl;
    return out;
}