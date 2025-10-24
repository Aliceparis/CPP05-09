#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void    test_signed(const Bureaucrat& bureau, AForm& formule)
{
    try
    {
        std::cout << bureau << std::endl;
        std::cout << formule << std::endl;
        formule.besigned(bureau);
        bureau.signForm(formule);
        formule.execute(bureau);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    test_no_signed(const Bureaucrat& bureau, AForm& formule)
{
    try 
    {
        std::cout << bureau << std::endl;
        std::cout << formule << std::endl;
        formule.execute(bureau);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
int main()
{
    Bureaucrat  hight_level("hight", 1);
    Bureaucrat  low_level("low", 150);
    
    Bureaucrat  no_execute_shrubbery("no_shrubbery", 140);
    Bureaucrat  no_execute_robot("no_robot", 50);
    Bureaucrat  no_execute_presidential("no_presidential", 10);

    AForm*  a = new ShrubberyCreationForm("a");
    AForm*  b = new RobotomyRequestForm("b");
    AForm*  c = new PresidentialPardonForm("c");

    std::cout << "==========test no signed =========== " << std::endl;
    test_no_signed(hight_level, *a);
    test_no_signed(hight_level, *b);
    test_no_signed(hight_level, *c);

    std::cout << "=====test signe failed======" << std::endl;
    test_signed(low_level, *a);
    test_signed(low_level, *b);
    test_signed(low_level, *c);

    std::cout << "======test for execution=====" << std::endl;
    test_signed(hight_level, *a);
    test_signed(hight_level, *b);
    test_signed(hight_level, *c);
    
    std::cout << "=====no execution=====" << std::endl;
    test_signed(no_execute_shrubbery, *a);
    test_signed(no_execute_robot, *b);
    test_signed(no_execute_presidential, *c);

    
    delete a;
    delete b;
    delete c;
    return 0;
}