#include "Base.hpp"

int main(void)
{
    Base *base = Base::generate();

    Base::identify(base);
    Base::identify(*base);

    Base::identify(NULL);

    delete base;
}