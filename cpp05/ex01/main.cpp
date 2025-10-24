#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    Bureaucrat  Zoe("zoe", 130);
    std::cout << Zoe << std::endl;

    std::cout << "======test Form construction=======" << std::endl;
    try
    {
        Form    Bob("bob", 120, 165); /*if it find the erro, it will not continue le next fonction*/
        std::cout << Bob << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try
    {
        std::cout << "========Test Form besigned=======" << std::endl;
        Form    Kevin("kevin", 120, 60);
        std::cout << Kevin << std::endl;
        Kevin.beSigned(Zoe);
        Zoe.signForm(Kevin);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    try 
    {
        std::cout << "========test Form besigned success=======" << std::endl;
        Bureaucrat  ABC("abc", 100);
        std::cout << ABC << std::endl;
        Form    Test("test", 120, 50);
        std::cout << Test << std::endl;
        Test.beSigned(ABC);
        ABC.signForm(Test);
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    std::cout << "======test signedForm failed=====" << std::endl;
    Bureaucrat  Bob("bob", 105);
    Form    form("form", 90, 50);
    Bob.signForm(form);
    std::cout << "======destroy======" << std::endl;
    return 0;
}

/*
try{} 形成了一个作用域（scope），任何{}内的生命变量都只存在于{},因为他们是在stack上面建立的，
所以当他们离开了作用域就会自动的被destroy，这也就是为什么kevin我们不能在try外面访问到
*/