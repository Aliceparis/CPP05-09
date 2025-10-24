#include "Form.hpp"

Form::Form() : _name(""), _is_signed(false),
               _grade_to_signe(100), _grade_to_execute(50)
{
    std::cout << "Form: Default constructor called" << std::endl;
}
Form::Form(const std::string &name, unsigned int sign, unsigned int execute) : _name(name), _is_signed(false),
                                                                               _grade_to_signe(sign), _grade_to_execute(execute)
{
    std::cout << "Form: Param constructor called" << std::endl;
    if (sign > 150 || execute > 150)
        throw Form::GradeTooLowException();
    else if (sign < 1 || execute < 1)
        throw Form::GradeTooHighException();
}
Form::Form(const Form &other) : _name(other._name), _is_signed(other._is_signed), _grade_to_signe(other._grade_to_signe),
                                _grade_to_execute(other._grade_to_execute)
{
    std::cout << "Form: Copy constructor called" << std::endl;
}
Form &Form::operator=(const Form &other)
{
    std::cout << "Form: assignment operator called" << std::endl;
    if (this != &other)
        _is_signed = other._is_signed;
    return *this;
}
Form::~Form()
{
    std::cout << "Form: destructor called" << std::endl;
}

/*getter*/
std::string Form::getName() const
{
    return (this->_name);
}
bool Form::get_is_signed() const
{
    return (this->_is_signed);
}
unsigned int Form::get_grade_signe() const
{
    return (this->_grade_to_signe);
}
unsigned int Form::get_grade_execute() const
{
    return (this->_grade_to_execute);
}

/*membre fonction*/
void Form::beSigned(const Bureaucrat &bureau)
{
    if (bureau.getGrade() <= this->get_grade_signe())
        this->_is_signed = true;
    else
        throw Form::GradeTooLowException();
}

std::ostream &operator<<(std::ostream &out, const Form &form)
{
    out << form.getName() << " | has grade to signe: "
        << form.get_grade_signe() << " | has grade to execute: "
        << form.get_grade_execute() << " | is signed: "
        << form.get_is_signed() << std::endl;
    return (out);
}