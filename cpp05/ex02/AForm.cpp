#include "AForm.hpp"
# define RED "\033[31m"
#define RESET   "\033[0m"

AForm::AForm(const std::string &name, unsigned int sign, unsigned int execute) : _grade_signe(sign), _grade_execute(execute),
                                                                                 _name(name), _is_signed(false)
{
    std::cout << RED << "AForm: constructor called" << RESET << std::endl;
    if (sign > 150 || execute > 150)
        throw AForm::GradeTooLowException();
    else if (sign < 1 || execute < 1)
        throw AForm::GradeTooHighException();
}
AForm::AForm(const AForm& other): _grade_signe(other._grade_signe), _grade_execute(other._grade_execute),
                                _name(other._name), _is_signed(other._is_signed)
{
    std::cout << RED << "AForm: copy constructor called" << RESET << std::endl;
}
AForm&  AForm::operator=(const AForm& other)
{
    std::cout << RED << "AForm: assignment operator called" << RESET << std::endl;
    if (this != &other)
        _is_signed = other._is_signed;
    return (*this);
}
AForm::~AForm()
{
    std::cout << RED << "AForm: destructor called" << RESET << std::endl;
}

/*getter*/
std::string AForm::getName() const
{
    return (this->_name);
}
unsigned int AForm::get_grade_signe() const
{
    return (this->_grade_signe);
}
unsigned int AForm::get_grade_execute() const
{
    return (this->_grade_execute);
}
bool AForm::get_is_signed() const
{
    return (this->_is_signed);
}
/*membre fonction*/
void AForm::besigned(const Bureaucrat &bureau)
{
    if (bureau.getGrade() > this->get_grade_signe())
        throw AForm::GradeTooLowException();
    this->_is_signed = true;
}
void AForm::execute(const Bureaucrat &execute) const
{
    if (!this->_is_signed)
        throw AForm::FormNotSigned();
    if (execute.getGrade() > this->get_grade_execute())
        throw AForm::GradeTooLowException();
    execute_action();
}

std::ostream &operator<<(std::ostream &out, const AForm &aform)
{
    out << aform.getName() << "| signed grade: " << aform.get_grade_signe()
        << "| execute grade: " << aform.get_grade_execute()
        << "| is signed: " << aform.get_is_signed() << std::endl;
    return (out);
}