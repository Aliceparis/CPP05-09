#include "AForm.hpp"

#define RED "\033[31m"
#define RESET "\033[0m"

AForm::AForm(const std::string &name, int sign_grade, int execute_grade) : _name(name), _grade_to_sign(sign_grade),
                                                                           _grade_to_execute(execute_grade), _is_signed(false)
{
    std::cout << RED << "AForm: Param constructor called" << RESET << std::endl;
    if (sign_grade < 1 || execute_grade < 1)
        throw AForm::GradeTooHighException();
    else if (sign_grade > 150 || execute_grade > 150)
        throw AForm::GradeTooLowException();
}
AForm::AForm(const AForm &other) : _name(other._name), _grade_to_sign(other._grade_to_sign),
                                   _grade_to_execute(other._grade_to_execute), _is_signed(other._is_signed)
{
    std::cout << RED << "AForm: Copy constructor called" << RESET << std::endl;
}
AForm&  AForm::operator=(const AForm& other)
{
    std::cout << RED << "AForm: assignment operator called" << RESET << std::endl;
    if (this != &other)
        _is_signed = other._is_signed;
    return *this;
}
AForm::~AForm()
{
    std::cout << RED << "AForm: destructor called" << RESET << std::endl;
}
/*getter*/
std::string AForm::getName() const
{
    return (_name);
}
int AForm::get_sign_grade() const
{
    return (_grade_to_sign);
}
int AForm::get_execute_grade() const
{
    return (_grade_to_execute);
}
bool    AForm::get_is_signed() const
{
    return _is_signed;
}

/*membre fonction*/
void    AForm::beSigned(const Bureaucrat& bureau)
{
    if (bureau.getGrade() > _grade_to_sign)
        throw AForm::GradeTooLowException();
    _is_signed = true;
}
void    AForm::execute(const Bureaucrat& executor) const
{
    if (!this->_is_signed)
        throw AForm::IsNotSigned();
    if (executor.getGrade() > this->_grade_to_execute)
        throw AForm::GradeTooLowException();
    execute_action();
}

std::ostream&   operator<<(std::ostream& out, const AForm& formule)
{
    out << RED << formule.getName() << "| sign_grade: " 
        << formule.get_sign_grade() << "| execute_grade: "
        << formule.get_execute_grade() << "| is_signed: "
        << formule.get_is_signed() << RESET << std::endl;
    return out;
}