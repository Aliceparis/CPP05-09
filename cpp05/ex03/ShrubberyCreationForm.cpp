#include "ShrubberyCreationForm.hpp"
#include <fstream>

#define RESET "\033[0m"
#define GREEN "\033[32m"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("")
{
    std::cout << GREEN << "ShrubberyCreationForm: Default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137),
                                                                          _target(target)
{
    std::cout << GREEN << "ShrubberyCreationForm: Param constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other), _target(other._target)
{
    std::cout << GREEN << "ShrubberyCreationForm: Copy constructor called" << RESET << std::endl;
}
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    std::cout << GREEN << "ShrubberyCreationForm: assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        AForm::operator=(other);
        _target = other._target;
    }
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << GREEN << "ShrubberyCreationForm: destructor called " << RESET << std::endl;
}

void    ShrubberyCreationForm::execute_action() const
{
    std::string filename(this->_target + "_shrubbery");
    std::ofstream   file(filename.c_str());

    if (file.is_open())
    {
        file << "     /*\\     \n";
        file << "    /***\\    \n";
        file << "   /*****\\   \n";
        file << "  /*******\\  \n";
        file << "      ||      \n";
        file << "      ||      \n";
        file.close();
        std::cout << "ASCII tree write successfully" << std::endl;
    }
    else
        std::cout << "Error: failed to create the file" << std::endl;
}

