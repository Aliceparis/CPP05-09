#include "ScalarConverter.hpp"
#include <iomanip>
#include <cmath>
#include <climits>

void    ScalarConverter::converte(const std::string &value)
{
    int  types = detecte_input_type(value);

    switch (types)
    {
        case TYPE_CHAR:
            converte_from_char(value);
            break;
        case TYPE_INT:
            converte_from_int(value);
            break;
        case TYPE_DOUBLE:
            converte_from_double(value);
            break;
        case TYPE_FLOAT:
            converte_from_float(value);
            break;
        case TYPE_PSEUDO_D:
            converte_from_pseudo_d(value);
            break;
        case TYPE_PSEUDO_F:
            converte_from_pseudo_f(value);
            break;
        default:
            std::cout << "Error: impossible to print or input not convertable" << std::endl;
            break ;        
    }
}
void    ScalarConverter::converte_from_char(const std::string &value)
{
    char    c = value[0];
    if (std::isprint(c))
        std::cout << "char: '" << c << "'" << std::endl;
    else
        std::cout << "char: Non displayable" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(c) << std::endl;
}
void    ScalarConverter::converte_from_int(const std::string &value)
{
    int i = atoi(value.c_str());

    if (i < 0 || i > 127)
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(i)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
    
    std::cout << "int: " << i << std::endl;
    std::cout << std::fixed << std::setprecision(1);
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}
void    ScalarConverter::converte_from_float(const std::string &value)
{
    const char* str = value.c_str();
    float   f = strtof(str, NULL);

    /*to char*/
    if (std::isnan(f) || std::isinf(f))
        std::cout << "char: impossible" << std::endl;
    else if (f < 0 || f > 127 || f != static_cast<int>(f))
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(f)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
    /*to int*/
    if (std::isnan(f) || std::isinf(f))
        std::cout << "int: impossible" << std::endl;
    else if (f < static_cast<float>(INT_MIN) || f > static_cast<float>(INT_MAX))
        std::cout << "int: impossible" << std::endl;
    else 
        std::cout << "int: " << static_cast<int>(f) << std::endl;
    /*to float*/
    if (std::isnan(f) || std::isinf(f))
        std::cout << "float: " << f << "f" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }
    /*to double*/
    if (std::isnan(f) || std::isinf(f))
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
}
void    ScalarConverter::converte_from_double(const std::string &value)
{
    const char* str = value.c_str();
    double  d = strtod(str, NULL);

    /*to char*/
    if (std::isnan(d) || std::isinf(d))
        std::cout << "char: impossible" << std::endl;
    else if (d < 0 || d > 127 || d != static_cast<int>(d))
        std::cout << "char: impossible" << std::endl;
    else if (!isprint(static_cast<char>(d)))
        std::cout << "char: Non displayable" << std::endl;
    else
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
    /*to int*/
    if (std::isnan(d) || std::isinf(d))
        std::cout << "int: impossible" << std::endl;
    else if (d > INT_MAX || d < INT_MIN)
        std::cout << "int: impossible" << std::endl;
    else
        std::cout << "int: " << static_cast<int>(d) << std::endl;
    /*to float*/
    float f = static_cast<float>(d);
    if (std::isnan(d) || std::isinf(d))
        std::cout << "float: " << f << "f" << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "float: " << f << "f" << std::endl;
    }
    /*to double*/
    if (std::isnan(d) || std::isinf(d))
        std::cout << "double: " << d << std::endl;
    else
    {
        std::cout << std::fixed << std::setprecision(1);
        std::cout << "double: " << d << std::endl;
    }
}
void    ScalarConverter::converte_from_pseudo_d(const std::string &value)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << value << "f" << std::endl;  // nan -> nanf
    std::cout << "double: " << value << std::endl;
}
void    ScalarConverter::converte_from_pseudo_f(const std::string &value)
{
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: " << value << std::endl;  // nanf, +inff, -inff
    
    // to double
    std::string double_ver = value.substr(0, value.length() - 1);  // 去掉 'f'
    std::cout << "double: " << double_ver << std::endl;
}