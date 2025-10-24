#include "ScalarConverter.hpp"
#define YELLOW  "\033[33m"
#define RESET   "\33[0m"
#include <cstdlib>
#include <cstring>
#include <climits>

ScalarConverter::ScalarConverter()
{
    std::cout << YELLOW << "ScalarConverter: default constructor called" << RESET << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
    std::cout << YELLOW << "ScalarConverter: copy constuctor called" << RESET << std::endl;
    *this = other;
}
ScalarConverter&    ScalarConverter::operator=(const ScalarConverter &other)
{
    std::cout << YELLOW << "ScalarConverter: assignment operator called" << RESET << std::endl;
    if (this == &other)
        return *this;
    return *this;
}
ScalarConverter::~ScalarConverter()
{
    std::cout << YELLOW << "ScalarConverter: destructor called" << RESET << std::endl;
}

input_type  ScalarConverter::detecte_input_type(const std::string &input)
{
    if (input.empty())
        return (TYPE_INVALID);
    /*check inf or nanf*/
    if (input == "nanf" || input == "-inff" || input == "+inff")
        return (TYPE_PSEUDO_F);
    if (input == "nan" || input == "-inf" || input == "+inf")
        return (TYPE_PSEUDO_D);
    /*check for char*/
    if (input.length() == 1 && std::isprint(input[0]) && !std::isdigit(input[0]))
        return (TYPE_CHAR);
    /*check for float*/
    if (input.length() > 1 && input[input.length() - 1] == 'f')
    {
        const char* str = input.c_str();
        char*   endptr;
        strtof(str, &endptr);
        if (endptr == &str[input.length() - 1] && *endptr == 'f')
            return (TYPE_FLOAT);
        return (TYPE_INVALID);
    }
    /*check for int double*/
    const char* str = input.c_str();
    char*   endptr;
    if (input.find('.') == std::string::npos)
    {
        errno = 0;
        long    d = strtol(str, &endptr, 10);
        if (*endptr == '\0' && d >= INT_MIN && d <= INT_MAX && errno == 0)
            return (TYPE_INT);
    }
    strtod(str, &endptr);
    if (*endptr == '\0')
        return(TYPE_DOUBLE);
    return (TYPE_INVALID);
}