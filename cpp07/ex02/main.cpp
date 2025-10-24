#include "Array.hpp"
#include "Array.tpp"

class   Student
{
    private:
        std::string _name;
        int _age;
    public:
        Student(): _name("unkown"), _age(0){};
        Student(const std::string &name, int age): _name(name), _age(age){
        };
        Student(const Student &other): _name(other._name), _age(other._age){
        };
        Student&    operator=(const Student &other){
            if (this != &other)
            {
                _name = other._name;
                _age = other._age;
            }
            return *this;
        };
        ~Student(){};
        /*membre fonction*/
        void    display() const{
            std::cout << this->_name << " has " << this->_age
                << " years old" << std::endl;
        };
};

void    print_header(const std::string &input)
{
    std::cout << "\n=========================" << std::endl;
    std::cout << input << std::endl;
    std::cout << "===========================" << std::endl;
}

int main()
{
    print_header("Test1: empty student array");
    {
        Array<Student>  emptyclass;
        std::cout << "emptyclass size: " << emptyclass.size() << std::endl;
    }
    print_header("Test2: classroom");
    {
        Array<Student> classroom(3);
        for(unsigned int i(0); i < classroom.size(); i++)
        {
            std::cout << "Index: " << i + 1 << ", ";
            classroom[i].display();
        }
    }
    print_header("Test3: classroom with student");
    {
        Array<Student> classroom(3);
        classroom[0] = Student("bob", 3);
        classroom[1] = Student("zoe", 4);
        classroom[2] = Student("claude", 3);
        for(unsigned int i(0); i < classroom.size(); i++)
        {
            std::cout << "Index: " << i + 1 << ", ";
            classroom[i].display();
        }
    }
    print_header("Test4: deep copy between classroom");
    {
        Array<Student> class1(3);
        class1[0] = Student("bob", 3);
        class1[1] = Student("zoe", 4);
        class1[2] = Student("claude", 3);
        for(unsigned int i(0); i < class1.size(); i++)
        {
            std::cout << "Index: " << i + 1 << ", ";
            class1[i].display();
        }
        Array<Student> class2(class1);
        std::cout << "now in class2: " << std::endl;
        for(unsigned int i(0); i < class2.size(); i++)
        {
            std::cout << "Index: " << i + 1 << ", ";
            class2[i].display();
        }
    }
    print_header("Test5: index out of range");
    {
        Array<Student> classroom(3);
        classroom[0] = Student("bob", 20);
        classroom[1] = Student("zoe", 19);
        try 
        {
            classroom[0].display();
            classroom[5].display();
        }
        catch (std::exception &e)
        {
            std::cout << "display failed because: " << e.what() << std::endl;
        }
    }
    print_header("Test6: const test");
    {
        Array<Student> classroom(2);
        classroom[0] = Student("bob", 20);
        classroom[1] = Student("zoe", 19);

        const Array<Student> class2 = classroom;
        for(unsigned int i(0); i < class2.size(); i++)
        {
            std::cout << "Index: " << i + 1 << ", ";
            class2[i].display();
        }
    }
    return 0;
}