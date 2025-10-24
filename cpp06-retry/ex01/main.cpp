#include "Serializer.hpp"

void    show_infos(data* ptr)
{
    std::cout << "id: " << ptr->_id << "| name: " 
        << ptr->_name << "| value: "
        << ptr->_value << std::endl;
}

int main(void)
{
    Data    data1 = {1, "zoe", 4.1};
    Data    data2 = {2, "bob", 11.0};

    std::cout << "=======test for data1======" << std::endl;
    uintptr_t   raw = Serializer::serialize(&data1);
    std::cout << "adress of data1: " << raw << std::endl;

    Data*   ptr1 = Serializer::deserialize(raw);
    std::cout << "ptr1 has infos: " << std::endl;
    show_infos(ptr1);

    std::cout << "=======test for data2======" << std::endl;
    uintptr_t   adress = Serializer::serialize(&data2);
    std::cout << "adress of data2: " << adress << std::endl;

    Data*   ptr2 = Serializer::deserialize(adress);
    std::cout << "ptr2 has infos: " << std::endl;
    show_infos(ptr2);

    return 0;
}