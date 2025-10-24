#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <cstdlib>

class PmergeMe
{
private:
    std::vector<int> _vect;
    std::deque<int> _deq;
    bool is_duplicate(int nbr) const;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe &operator=(const PmergeMe &other);
    ~PmergeMe();

    /*membre fonction*/
    int parse(int ac, char **av);

    /*sort vect*/
    void recursive_vect(std::vector<int> &_data);
    void splite_pairing_vect(std::vector<int> &input, std::vector<int> &main_chaine,
                             std::vector<int> &pend, int &last_one);
    std::vector<size_t> get_jacobsthal(size_t size) const;
    void binary_insert_vect(int value, std::vector<int> &main_chaine);

    /*sort deque*/
    void recursive_deque(std::deque<int> &_data);
    void splite_pairing_deq(std::deque<int> &input, std::deque<int> &chaine,
                            std::deque<int> &pend, int &last_one);
    std::deque<size_t> get_jacobsthal_deque(size_t n) const;
    void binary_insert_deque(std::deque<int> &chaine, int value);

    /*print before*/
    void print_vect() const;
    void print_deq() const;
    /*print after sort*/
    void sort_vect();
    void sort_deq();

    /*getter*/
    std::vector<int> get_vect() const;
    std::deque<int> get_deque() const;
    /*check input*/
    long get_valide_input(const std::string &input);
};

#endif