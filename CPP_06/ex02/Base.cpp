#include "Base.hpp"

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base() {
}

Base * Base::generate(void)
{
    std::srand(static_cast<unsigned>(std::time(0)));
    int randomIndex = std::rand() % 3;

    if (randomIndex == 0)
        return (new A);
    else if (randomIndex == 1)
        return (new B);
    else
        return (new C);
}

void Base::identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
    else
        std::cout << "Unknown" << std::endl;
}

void Base::identify(Base& p)
{
    try {
        (void)dynamic_cast<const A&>(p);
        std::cout << "A" << std::endl;
    } catch (const std::bad_cast&)
    {
        try {
            (void)dynamic_cast<const B&>(p);
            std::cout << "B" << std::endl;
        } catch (const std::bad_cast&)
        {
            try {
                (void)dynamic_cast<const C&>(p);
                std::cout << "C" << std::endl;
            } catch (const std::bad_cast&)
            {
                std::cout << "Unknown" << std::endl;
            }
        }
    }
}