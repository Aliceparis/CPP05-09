#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <string>
#include <cerrno> 

enum    input_type
{
    TYPE_CHAR = 0,
    TYPE_INT = 1,
    TYPE_FLOAT = 2,
    TYPE_DOUBLE = 3,
    TYPE_PSEUDO_F = 4,
    TYPE_PSEUDO_D = 5,
    TYPE_INVALID = 6
};

class   ScalarConverter
{
    private:
        ScalarConverter();
        ScalarConverter(const ScalarConverter &other);
        ScalarConverter&    operator=(const ScalarConverter &other);
        ~ScalarConverter();

        static input_type  detecte_input_type(const std::string &input);
        static void    converte_from_char(const std::string &value);
        static void    converte_from_int(const std::string &value);
        static void    converte_from_double(const std::string &value);
        static void    converte_from_float(const std::string &value);
        static void    converte_from_pseudo_f(const std::string &value);
        static void    converte_from_pseudo_d(const std::string &value);
    public:
        static void    converte(const std::string &value);
        
};


#endif