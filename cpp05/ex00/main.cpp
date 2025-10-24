#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat  Zoe("zoe", 160);
        std::cout << Zoe << std::endl;
    }
    catch (std::exception& e)
    {
        std::cerr << e.what() << std::endl; 
    }
    try 
    {
        std::cout << "=======test decrement/increment=======" << std::endl;
        Bureaucrat  Kevin("kevin", 100);
        std::cout << Kevin << std::endl;
        Kevin.decrement_grade();
        std::cout << Kevin << std::endl;
        Kevin.increment_grade();
        std::cout << Kevin << std::endl;

        Bureaucrat  Ralphe("ralphe", 150);
        std::cout << Ralphe << std::endl;
        Ralphe.increment_grade();
    }
    catch(std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

/*
try catch 的处理位置： 
如果在constructor当中添加了try catch，那么Zoe还是会被成功建立，
外体的try catch到的是constructor当中的error，error在constructor当中被处理成功，
然后导致constructor正常完成，Zoe被成功创建。

而把constructor当中的try去掉以后，try发现在constructor时出现了问题，所以没有把zoe创建成功，
因此后面的fonction就不能够继续

*/