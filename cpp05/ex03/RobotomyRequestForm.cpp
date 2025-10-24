#include "RobotomyRequestForm.hpp"
#include <cstdlib>

#define BLUE "\033[34m"
#define RESET "\033[0m"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),
                                             _target("")
{
    std::cout << BLUE << "RobotomyRequestForm: Default constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45),
                                                                      _target(target)
{
    std::cout << BLUE << "RobotomyRequestForm: Param constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other), _target(other._target)
{
    std::cout << BLUE << "RobotomyRequestForm: Copy constructor called" << RESET << std::endl;
}
RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
    std::cout << BLUE << "RobotomyRequestForm: assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << BLUE << "RobotomyRequestForm: destructor called" << RESET << std::endl;
}

/*membre fonction*/
void    RobotomyRequestForm::execute_action() const
{
    std::cout << "Bzzzzzz... drrrrrr.... *drilling noises*" << std::endl;
    if (std::rand() % 2)
        std::cout << _target << " has been robotomized successfully" << std::endl;
    else
        std::cout << "Robotomy failed on " << _target << "!" << std::endl;
}