#include "Data.hpp"

Data::Data() : iD("default"){
}

Data::Data(std::string iD) : iD(iD){
}

Data::Data(const Data &other) {
    *this = other;
}

Data& Data::operator=(const Data &other) {
    this->iD = other.iD;
    return (*this);
}

Data::~Data() {
}

// -------------------------- //

