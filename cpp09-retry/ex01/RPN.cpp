#include "RPN.hpp"
#include <sstream>
#include <cstdlib>
#include <cerrno>
#include <climits>

Rpn::Rpn() {}

Rpn::Rpn(const Rpn &other)
{
    *this = other;
}
Rpn &Rpn::operator=(const Rpn &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}
Rpn::~Rpn() {}

/*membre fonction*/
bool Rpn::is_number(const std::string &token, long &resultat) const
{
    char *end = NULL;
    errno = 0;
    long nbr = strtol(token.c_str(), &end, 10);

    if (*end != '\0' || end == token.c_str())
        return false;
    if (errno == ERANGE)
        throw std::runtime_error("Error: out of range int");
    if (nbr < 0 || nbr > 10)
        throw std::out_of_range("Error: number have to between 0-10");
    resultat = nbr;
    return true;
}

bool Rpn::is_operator(const std::string &token) const
{
    return (token == "+" || token == "-" || token == "/" || token == "*");
}

void Rpn::calcule(const std::string &input)
{
    if (_data.size() < 2)
        throw std::runtime_error("Error");
    long top = _data.top();
    _data.pop();
    long seconde = _data.top();
    _data.pop();

    long resultat;
    if (input == "+")
        resultat = top + seconde;
    else if (input == "-")
        resultat = seconde - top;
    else if (input == "*")
        resultat = top * seconde;
    else if (input == "/")
    {
        if (top == 0)
            throw std::runtime_error("Error: division of zero");
        resultat = seconde / top;
    }
    else
        throw std::runtime_error("Error: unkown operator");
    // std::cout << "Top: " << top << "| seconde: " << seconde << "| resultat: "
      //       << resultat << "| operator: " << input << std::endl;
    if (resultat >= INT_MAX)
        throw std::out_of_range("Error: resultat is out of range int max");
    _data.push(resultat);
}

void Rpn::processe(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;
    long nbr;

    while (iss >> token)
    {
        if (is_number(token, nbr))
            _data.push(nbr);
        else if (is_operator(token))
            calcule(token);
        else
            throw std::runtime_error("Error: invalide input");
    }
}

void Rpn::load_info(const std::string &input)
{
    std::istringstream iss(input);
    std::string token;

    while (iss >> token)
        processe(token);
    if (_data.size() != 1)
        throw std::runtime_error("Error");
    std::cout << _data.top() << std::endl;
}
/*debug*/
void Rpn::display()
{
    std::cout << "Elements in the stack: ";

    while (!_data.empty())
    {
        std::cout << _data.top() << " ";
        _data.pop();
    }
    std::cout << std::endl;
}