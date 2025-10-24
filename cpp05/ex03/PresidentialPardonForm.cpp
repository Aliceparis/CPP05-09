#include "PresidentialPardonForm.hpp"

#define MAGENTA "\033[35m"
#define RESET "\033[0m"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5), _target("")
{
    std::cout << MAGENTA << "PresidentialPardonForm: Default constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardonForm", 25, 5),
                                                                            _target(target)
{
    std::cout << MAGENTA << "PresidentialPardonForm: Param constructor called" << RESET << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other), _target(other._target)
{
    std::cout << MAGENTA << "PresidentialPardonForm: Copy constructor called" << RESET << std::endl;
}
PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
    std::cout << MAGENTA << "PresidentialPardonForm: assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
PresidentialPardonForm::~PresidentialPardonForm()
{
    std::cout << MAGENTA << "PresidentialPardonForm: destructor called" << RESET << std::endl;
}

/*membre fonction*/
void    PresidentialPardonForm::execute_action() const
{
    std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
