#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>

class Base {
private:

public:
    virtual ~Base();

    static Base * generate(void);
    static void identify(Base* p);
    static void identify(Base& p);
};