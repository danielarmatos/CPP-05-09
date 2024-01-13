#include "Serializer.hpp"

int main(void)
{
    Data* data = new Data("Hello");
    std::cout << data << std::endl;

    uintptr_t value;
    value = Serializer::serialize(data);
    std::cout << &value << std::endl;
    std::cout << value << std::endl;

    Data* data2 = Serializer::deserialize(value);
    std::cout << data2 << std::endl;

    if (data == data2)
        std::cout << "The values are the same!" << std::endl;
    else
        std::cout << "Error, the values are not the same" << std::endl;

    delete data;
}