#include "MutantStack.hpp"
#include "MutantStack.tpp"

void    print_header(const std::string &input)
{
    std::cout << "\n==========================" << std::endl;
    std::cout << input << std::endl;
    std::cout << "================================" << std::endl;
}
void    test_stack_fonctions(MutantStack<int> &ms)
{
    print_header("Test1: test stack fonction");
    ms.push(1);
    ms.push(5);
    ms.push(10);
    ms.push(15);
    std::cout << ms << std::endl;
    std::cout << "top element: " << ms.top() << std::endl;
    ms.pop();
    std::cout << "after delete the first element, " << ms << std::endl;
}
void    test_sujet(MutantStack<int> &mstack)
{
    print_header("Test of subjet");
    mstack.push(5);
    mstack.push(17);
    std::cout << "top element: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "size of mstack: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    //[...]
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite)
    {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);
}
int main()
{
    MutantStack<int>    mstack;

    test_stack_fonctions(mstack);
    test_sujet(mstack);
    return 0;
}