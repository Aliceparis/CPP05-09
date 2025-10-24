#include "RobotomyRequestForm.hpp"
#define YELLOW  "\033[33m" 
#define RESET   "\033[0m"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45),
                                             _target("")
{
    std::cout << YELLOW << "RobotomyRequestForm: Default constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const std::string& target): AForm("RobotomyRequestForm", 72, 45),
    _target(target)
{
    std::cout << YELLOW << "RobotomyRequestForm: Param constructor called" << RESET << std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other):AForm(other), _target(other._target)
{
    std::cout << YELLOW << "RobotomyRequestForm: copy constructor called" << RESET << std::endl;
}
RobotomyRequestForm&    RobotomyRequestForm::operator=(const RobotomyRequestForm& other)
{
    std::cout << YELLOW << "RobotomyRequestForm: assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        _target = other._target;
        AForm::operator=(other);
    }
    return *this;
}
RobotomyRequestForm::~RobotomyRequestForm()
{
    std::cout << YELLOW << "RobotomyRequestForm: destructor called" << RESET << std::endl;
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