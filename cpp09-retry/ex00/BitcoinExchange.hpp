#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <cerrno>
#include <fstream>

class   BitcoinExchange
{
    private:
        std::map<std::string, float>    _data;
        bool    is_valide_date(const std::string &date);
        int get_number(const std::string &str, size_t start, size_t len);
        float   get_valide_price(const std::string &price, bool &sucess);

    public:
        BitcoinExchange();
        BitcoinExchange(const BitcoinExchange &other);
        BitcoinExchange&    operator=(const BitcoinExchange &other);
        ~BitcoinExchange();

        /*membre fonction*/
        void    load_database(const std::string &base);
        void    process_exchange(const std::string &file);
        float   find_the_price_with_day(const std::string &day) const;
};



#endif