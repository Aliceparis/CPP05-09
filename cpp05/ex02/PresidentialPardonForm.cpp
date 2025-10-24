#include "PresidentialPardonForm.hpp"
#define CYAN "\033[36m"
#define RESET "\033[0m"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),
                                                   _target("")
{
    std::cout << CYAN << "PresidentialPardonForm: Default constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5),
                                                                            _target(target)
{
    std::cout << CYAN << "PresidentialPardonForm: Param constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other),
                                                                                      _target(other._target)
{
    std::cout << CYAN << "PresidentialPardonForm: Copy constructor called" << RESET << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other)
{
    std::cout << CYAN << "PresidentialPardonForm: assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << CYAN << "PresidentialPardonForm: destructor called" << RESET << std::endl;
}

/*membre fonction*/
void    PresidentialPardonForm::execute_action() const
{
    std::cout << this->_target << " has been pardonned by Zaphod Beeblebrox." << std::endl;
}