#pragma once

#include <iostream>

class Data {
private:
    std::string iD;
public:
    Data();
    Data(std::string iD);
    Data(const Data& other);
    Data & operator=(const Data& other);
    ~Data();
};
