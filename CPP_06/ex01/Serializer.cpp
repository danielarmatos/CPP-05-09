#include "Serializer.hpp"

Serializer::Serializer() {
}

Serializer::Serializer(const Serializer&) {
}

Serializer& Serializer::operator=(const Serializer &) {
    return (*this);
}

Serializer::~Serializer() {
}

// -------------------------- //

/* reinterpret_cast:
 * used to convert a pointer of some data type into a pointer of another data type */

uintptr_t Serializer::serialize(Data* ptr)
{
    uintptr_t result = reinterpret_cast<uintptr_t>(ptr);
    return (result);
}

Data* Serializer::deserialize(uintptr_t raw)
{
    Data *result = reinterpret_cast<Data *>(raw);
    return (result);
}