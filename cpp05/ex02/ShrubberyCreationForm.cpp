#include "ShrubberyCreationForm.hpp"
#define BLUE    "\033[34m" 
#define RESET   "\033[0m"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("")
{
    std::cout << BLUE << "ShrubberyCreationForm: Default constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137),
                                                                          _target(target)
{
    std::cout << BLUE << "ShrubberyCreationForm: Param constructor called" << RESET << std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other): AForm(other), _target(other._target)
{
    std::cout << BLUE << "ShrubberyCreationForm: Copy constructor called" << RESET << std::endl;
}
ShrubberyCreationForm&  ShrubberyCreationForm::operator=(ShrubberyCreationForm& other)
{
    std::cout << BLUE << "ShrubberyCreationForm: assignment operator called" << RESET << std::endl;
    if (this != &other)
    {
        this->_target = other._target;
        AForm::operator=(other);
    }
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << BLUE << "ShrubberyCreationForm: destructor called" << RESET << std::endl;
}

/*membre fonction*/
void    ShrubberyCreationForm::execute_action() const
{
    std::string filename(_target + "_shrubbery");
    std::ofstream   write_file(filename.c_str());
    if (write_file.is_open())
    {   
        write_file << "        /*\\        \n";
        write_file << "       /***\\       \n";
        write_file << "      /*****\\      \n";
        write_file << "     /*******\\     \n";
        write_file << "    /*********\\    \n";
        write_file << "         ||         \n";
        write_file << "         ||         \n";
        write_file.close();
        std::cout << "ASCII tree write in the file success!" << std::endl;
    }
    else
        std::cout << "Failed to create the file" << std::endl;
}