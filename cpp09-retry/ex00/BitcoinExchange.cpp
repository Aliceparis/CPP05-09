#include "BitcoinExchange.hpp"
#include <limits>

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : _data(other._data) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
    if (this != &other)
        _data = other._data;
    return *this;
}
BitcoinExchange::~BitcoinExchange() {}

/*membre fonction*/
int BitcoinExchange::get_number(const std::string &str, size_t start, size_t len)
{
    int resultat = 0;

    for (size_t i(0); i < len; i++)
    {
        if (!std::isdigit(static_cast<unsigned char>(str[start + i])))
            return -1;
        resultat = resultat * 10 + (str[start + i] - '0');
    }
    return resultat;
}

bool BitcoinExchange::is_valide_date(const std::string &date)
{
    if (date.size() != 10 || date.at(4) != '-' || date.at(7) != '-')
        return false;
    int year = get_number(date, 0, 4);
    int month = get_number(date, 5, 2);
    int day = get_number(date, 8, 2);

    if (year == -1 || month == -1 || day == -1)
        return false;
    if (year < 2009 || year > 2050)
        return false;
    if (month < 1 || month > 12)
        return false;
    if (day < 1 || day > 31)
        return false;

    /*check day for month*/
    static const int day_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int max_day = day_in_month[month - 1];
    if (month == 2)
    {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
            max_day = 29;
    }
    return (day <= max_day);
}
float BitcoinExchange::get_valide_price(const std::string &price, bool &sucess)
{
    char *end = NULL;
    errno = 0;
    float resultat = std::strtof(price.c_str(), &end);

    if (errno == ERANGE)
    {
        sucess = false;
        return 0.0f;
    }
    while (*end != '\0')
    {
        if (!std::isspace(static_cast<int>(*end)))
        {
            sucess = false;
            return 0.0f;
        }
        end++;
    }
    sucess = true;
    return resultat;
}

void BitcoinExchange::load_database(const std::string &base)
{
    std::fstream database(base.c_str());
    /*open the file*/
    if (!database.is_open())
        throw std::runtime_error("Error: failed to open database file");
    /*read the file*/
    std::string line;
    std::getline(database, line); /*skip the first line*/
    while (std::getline(database, line))
    {
        size_t pos = line.find(",");
        if (pos != std::string::npos)
        {
            std::string date_str = line.substr(0, pos);
            std::string rate_str = line.substr(pos + 1);
            if (!is_valide_date(date_str))
            {
                throw std::runtime_error("Error: date in database is invalide");
                continue;
            }
            bool sucess = false;
            float rate = get_valide_price(rate_str, sucess);
            if (!sucess)
            {
                throw std::runtime_error("Error: exchange rate in database is invalide");
                continue;
            }
            _data[date_str] = rate;
        }
        else
            std::cout << "Error: format in database invalide" << std::endl;
    }
    database.close();
}
float BitcoinExchange::find_the_price_with_day(const std::string &day) const
{
    if (_data.empty())
        return -1.0f;
    std::map<std::string, float>::const_iterator it;
    it = _data.lower_bound(day);

    /*case1: date is before 2009-01-02*/
    if (it == _data.begin())
        return -1.0f;
    else if (it != _data.end() && it->first == day)
        return it->second;
    else if (it != _data.end() && it->first != day)
    {
        it--;
        return it->second;
    }
    return -1.0f;
}
void BitcoinExchange::process_exchange(const std::string &file)
{
    std::fstream filename(file.c_str());
    /*open the file*/
    if (!filename.is_open())
        throw std::runtime_error("Error: failed to open the file from the input");
    /*read the file*/
    std::string line;
    std::getline(filename, line); /*skip the first line*/
    while (std::getline(filename, line))
    {
        size_t pos = line.find(" | ");
        if (pos != std::string::npos)
        {
            std::string date_str = line.substr(0, pos);
            std::string value_str = line.substr(pos + 3);
            if (!is_valide_date(date_str))
            {
                std::cout << "Error: bad input => " << date_str << std::endl;
                continue;
            }
            bool sucess = false;
            float value = get_valide_price(value_str, sucess);
            if (value < 0.0f)
            {
                std::cout << "Error: not a positive number" << std::endl;
                continue;
            }
            else if (value > 1000.0f)
            {
                std::cout << "Error: too large a number" << std::endl;
                continue;
            }
            float exchange_rate = find_the_price_with_day(date_str);
            if (exchange_rate > 0.0f)
                std::cout << date_str << " => " << value_str << " = " << exchange_rate * value << std::endl;
        }
        else
            std::cout << "Error: bad input => " << line << std::endl;
    }
}