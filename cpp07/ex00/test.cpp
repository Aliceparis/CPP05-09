#include "whatever.hpp"
#include <iostream>

class   Place
{
    private:
        int _n;
    public:
        Place(): _n(0){};
        Place(int n): _n(n){};
        Place&  operator=(const Place &a){
            _n = a._n;
            return *this;};
        ~Place(){};
        int get_n() const{
            return _n;};
        bool    operator==(const Place &a) const{
            return (this->_n == a._n);};
        bool    operator!=(const Place &a) const{
            return !(*this == a);};
        bool    operator>(const Place &a) const{
            return (this->_n > a._n);};
        bool    operator<(const Place &a) const{
            return !(*this > a);
        };    
};
std::ostream&   operator<<(std::ostream& out, const Place &a)
{
    out << a.get_n();
    return out;
}

int main()
{
    Place   a(2), b(5);

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    swap(a, b);
    std::cout << "max between a b: " << max(a, b) << std::endl;
    std::cout << "min between a b: " << min(a, b) << std::endl;
    b = 5;
    std::cout << "min between a b: " << min(a, b) << std::endl;
    return 0;
}