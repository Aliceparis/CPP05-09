#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name(""), _grade(150)
{
    std::cout << "Bureaucrat: Default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const std::string &name, unsigned int grade) : _name(name),
                                                                      _grade(150)
{
    std::cout << "Bureaucrat: Param constructor called" << std::endl;
    setGrade(grade);
}
Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade)
{
    std::cout << "Bureaucrat: Copy constructor called" << std::endl;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
    std::cout << "Bureaucrat: assignment operator called" << std::endl;
    if (this != &other)
        this->_grade = other._grade;
    return (*this);
}
Bureaucrat::~Bureaucrat()
{
    std::cout << "Bureaucrat: destructor called " << this->_name << std::endl;
}

/*membre fonction*/
void Bureaucrat::setGrade(unsigned int grade)
{
    if (grade > 150)
        throw Bureaucrat::GradeTooLowException();
    else if (grade < 1)
        throw Bureaucrat::GradeTooHighException();
    _grade = grade;
}
std::string Bureaucrat::getName() const
{
    return (this->_name);
}
unsigned int Bureaucrat::getGrade() const
{
    return (this->_grade);
}
void Bureaucrat::increment_grade()
{
    try
    {
        unsigned int tmp(this->getGrade());
        setGrade(tmp + 1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void Bureaucrat::decrement_grade()
{
    try
    {
        unsigned int tmp(this->getGrade());
        setGrade(tmp - 1);
    }
    catch (std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void Bureaucrat::signForm(Form &form) const
{
    try
    {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << this->getName() << " couldn't sign " << form.getName()
                  << " because " << e.what() << std::endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureau)
{
    out << bureau.getName() << ", bureaucrat grade " << bureau.getGrade() << std::endl;
    return (out);
}