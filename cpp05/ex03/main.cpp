#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

void    test_sign(const Bureaucrat &bureau, const AForm &formule)
{
    try 
    {
        formule.execute(bureau);
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
}
void    test_execution(const Bureaucrat &bureau, AForm &formule)
{
    try 
    {
        formule.beSigned(bureau);
        bureau.executeForm(formule);
    }
    catch(std::exception &e)
    {
        std::cerr << e.what() << std::endl;
    }
}

int main()
{
    Intern  randomintern;
    AForm*  rrf;
    Bureaucrat  hight_level("high", 1);

    std::cout << "======test shrubbery======" << std::endl;
    Bureaucrat  no_execute_shrubbery("no_shrubbery", 140);
    rrf = randomintern.makeForm("ShrubberyCreationForm", "chloe");
    std::cout << hight_level << std::endl;
    std::cout << no_execute_shrubbery << std::endl;
    std::cout << *rrf << std::endl;
    test_sign(hight_level, *rrf);
    test_execution(hight_level, *rrf);
    test_execution(no_execute_shrubbery, *rrf);
    delete rrf;

    std::cout << "=======test robot======" << std::endl;
    Bureaucrat  no_execute_robot("no_robot", 60);
    rrf = randomintern.makeForm("RobotomyRequestForm", "ralphe");
    std::cout << no_execute_robot << std::endl;
    std::cout << *rrf << std::endl;
    test_sign(hight_level, *rrf);
    test_execution(no_execute_robot, *rrf);
    test_execution(hight_level, *rrf);
    delete rrf;

    std::cout << "=======test president======" << std::endl;
    Bureaucrat  no_execute_president("no_president", 10);
    rrf = randomintern.makeForm("PresidentialPardonForm", "zoe");
    std::cout << no_execute_president << std::endl;
    std::cout << *rrf << std::endl;
    test_sign(hight_level, *rrf);
    test_execution(no_execute_president, *rrf);
    test_execution(hight_level, *rrf);
    delete rrf;

    std::cout << "======makeform faile======" << std::endl;
    rrf = randomintern.makeForm("formule", "zoe");
    return 0;
}