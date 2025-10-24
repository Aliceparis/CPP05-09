#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <iostream>
#include <stdint.h>

typedef struct  data
{
    int _id;
    std::string _name;
    double  _value;
}Data;

class   Serializer
{
    private:
        Serializer();
        Serializer(const Serializer &other);
        Serializer& operator=(const Serializer &other);
        virtual ~Serializer() = 0;

    public:
        /*membre fonction*/
        static uintptr_t serialize(Data* ptr);
        static Data* deserialize(uintptr_t raw);

};



#endif