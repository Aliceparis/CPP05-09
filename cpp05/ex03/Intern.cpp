#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::Intern()
{
    std::cout << "Intern: Default constructor called" << std::endl;
}
Intern::Intern(const Intern &other)
{
    (void)other;
}
Intern& Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}
Intern::~Intern()
{
}

/*membre fonction*/
AForm*  Intern::make_shrubbery(const std::string &target)
{
    return (new ShrubberyCreationForm(target));
}
AForm*  Intern::make_robot(const std::string &target)
{
    return (new RobotomyRequestForm(target));
}
AForm*  Intern::make_president(const std::string &target)
{
    return (new PresidentialPardonForm(target));
}

AForm*  Intern::makeForm(const std::string &name, const std::string &target)
{
    std::string formes[3] = {"ShrubberyCreationForm", "RobotomyRequestForm", "PresidentialPardonForm"};
    
    AForm*    (Intern::*fonctions[])(const std::string &) = {
        &Intern::make_shrubbery,
        &Intern::make_robot,
        &Intern::make_president
    };

    for(int i = 0; i < 3; i++)
    {
        if (formes[i] == name)
        {
            std::cout << "Intern creates " << name << std::endl;
            return (this->*fonctions[i])(target);
        }
    }
    std::cout << "Intern can't find the form: " << name << std::endl;
    return NULL;
}