#include "PmergeMe.hpp"
#include <cerrno>
#include <climits>

PmergeMe::PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &other) : _vect(other._vect), _deq(other._deq) {}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
    if (this != &other)
    {
        _vect = other._vect;
        _deq = other._deq;
    }
    return *this;
}
PmergeMe::~PmergeMe() {}

/*membre fonction*/
long PmergeMe::get_valide_input(const std::string &input)
{
    char *end = NULL;
    errno = 0;
    long long_nbr = std::strtol(input.c_str(), &end, 10);

    /*check errno*/
    if (errno == ERANGE)
        throw std::out_of_range("Error: input out of range long");
    /*check end */
    if (*end != '\0')
        throw std::runtime_error("Error: invalide character find in the number");
    /*check int max */
    if (long_nbr > INT_MAX || long_nbr < 0)
        throw std::out_of_range("Error: nbr out of range int");
    return long_nbr;
}

bool PmergeMe::is_duplicate(int n) const
{
    for (std::vector<int>::const_iterator it = _vect.begin(); it != _vect.end(); it++)
    {
        if (*it == n)
            return true;
    }
    return false;
}

int PmergeMe::parse(int ac, char **av)
{
    if (ac < 3)
    {
        std::cout << "Error: need at least 2 numbers" << std::endl;
        return -1;
    }
    for (int i(1); i < ac; i++)
    {

        try
        {
            long long_nbr = get_valide_input(av[i]);
            int nbr = static_cast<int>(long_nbr);
            if (is_duplicate(nbr))
                throw std::runtime_error("Error: double nbr found");
            _vect.push_back(nbr);
            _deq.push_back(nbr);
        }
        catch (std::exception &e)
        {
            std::cout << e.what() << std::endl;
            _vect.clear();
            _deq.clear();
            return -1;
        }
    }
    return 0;
}
/*sort vect*/
void PmergeMe::splite_pairing_vect(std::vector<int> &input, std::vector<int> &main_chaine,
                                   std::vector<int> &pend, int &last_one)
{
    for (size_t i(0); i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            main_chaine.push_back(input[i]);
            pend.push_back(input.at(i + 1));
        }
        else
        {
            main_chaine.push_back(input[i + 1]);
            pend.push_back(input[i]);
        }
    }
    if (input.size() % 2 != 0)
        last_one = input.back();
}

std::vector<size_t> PmergeMe::get_jacobsthal(size_t size) const
{
    std::vector<size_t> resultat;
    std::set<size_t> used;

    size_t j0 = 0;
    size_t j1 = 1;
    while (j1 < size)
    {
        if (used.insert(j1).second)
            resultat.push_back(j1);
        size_t next = j1 + 2 * j0;
        j0 = j1;
        j1 = next;
    }
    for (size_t i(0); i < size; i++)
    {
        if (used.find(i) == used.end())
            resultat.push_back(i);
    }
    return (resultat);
}
void PmergeMe::binary_insert_vect(int value, std::vector<int> &main_chaine)
{

    std::vector<int>::iterator it;
    it = std::lower_bound(main_chaine.begin(), main_chaine.end(), value);
    main_chaine.insert(it, value);
}
void PmergeMe::recursive_vect(std::vector<int> &_data)
{
    std::vector<int> S;
    std::vector<int> P;
    int last_one = -1;

    if (_data.size() <= 1)
        return;
    splite_pairing_vect(_data, S, P, last_one);
    recursive_vect(S);
    if (!P.empty())
        S.insert(S.begin(), P[0]);
    /*find index of pend to insert*/
    std::vector<size_t> insert_index;
    if (P.size() > 1)
    {
        insert_index = get_jacobsthal(P.size());
        for (size_t i(0); i < insert_index.size(); i++)
            insert_index[i]++;
    }
    /*insert the pend to main chaine*/
    for (size_t i(0); i < insert_index.size(); i++)
    {
        size_t index = insert_index[i];
        if (index < P.size())
        {
            int value = P[index];
            binary_insert_vect(value, S);
        }
    }
    if (last_one != -1)
        binary_insert_vect(last_one, S);
    _data = S;
}

/*sort deque*/
void PmergeMe::splite_pairing_deq(std::deque<int> &input, std::deque<int> &chaine,
                                  std::deque<int> &pend, int &last_one)
{
    for(size_t i = 0; i + 1 < input.size(); i += 2)
    {
        if (input[i] > input[i + 1])
        {
            chaine.push_back(input[i]);
            pend.push_back(input[i + 1]);
        }
        else
        {
            chaine.push_back(input.at(i + 1));
            pend.push_back(input.at(i));
        }
    }
    if (input.size() % 2 != 0)
        last_one = input.back();
}
std::deque<size_t>  PmergeMe::get_jacobsthal_deque(size_t n) const
{
    std::deque<size_t>  resultat;
    std::set<size_t>    used;
    size_t  j0 = 0;
    size_t  j1 = 1;

    while (j1 < n)
    {
        if (used.insert(j1).second)
            resultat.push_back(j1);
        size_t  next = j0 + 2;
        j0 = j1;
        j1 = next;
    }
    for(size_t i = 0; i < n; i++)
    {
        if (used.find(i) == used.end())
            resultat.push_back(i);
    }
    return resultat;
}

void    PmergeMe::binary_insert_deque(std::deque<int> &chaine, int value)
{
    std::deque<int>::iterator it;

    it = std::lower_bound(chaine.begin(), chaine.end(), value);
    chaine.insert(it, value);
}

void PmergeMe::recursive_deque(std::deque<int> &_data)
{
    std::deque<int> main_chaine;
    std::deque<int> pend;
    int last_one = -1;

    if (_data.size() <= 1)
        return;
    splite_pairing_deq(_data, main_chaine, pend, last_one);
    recursive_deque(main_chaine);
    if (!pend.empty())
        main_chaine.insert(main_chaine.begin(), pend[0]);
    /*find index of pend*/
    std::deque<size_t> insert_index;
    if (pend.size() > 1)
    {
        insert_index = get_jacobsthal_deque(pend.size() - 1);
        for (size_t i(0); i < insert_index.size(); i++)
            insert_index[i]++;
    }
    /*insert pend to main chaine*/
    for (size_t i = 0; i < insert_index.size(); i++)
    {
        size_t index = insert_index[i];
        if (index < pend.size())
        {
            int value = pend[index];
            binary_insert_deque(main_chaine, value);
        }
    }
    if (last_one != -1)
        binary_insert_deque(main_chaine, last_one);
    _data = main_chaine;
}

/*print before*/
void PmergeMe::print_vect() const
{
    for (std::vector<int>::const_iterator it = _vect.begin(); it != _vect.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

void PmergeMe::print_deq() const
{
    for (std::deque<int>::const_iterator it = _deq.begin(); it != _deq.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}

/*getter*/
std::vector<int> PmergeMe::get_vect() const
{
    return _vect;
}
std::deque<int> PmergeMe::get_deque() const
{
    return _deq;
}
/*print after sort*/
void PmergeMe::sort_vect()
{
    std::vector<int> data = get_vect();

    recursive_vect(data);
    for (std::vector<int>::const_iterator it = data.begin(); it != data.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;
}
void PmergeMe::sort_deq()
{
    std::deque<int> data = get_deque();

    recursive_deque(data);
    /*for (std::deque<int>::const_iterator it = data.begin(); it != data.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;*/
}