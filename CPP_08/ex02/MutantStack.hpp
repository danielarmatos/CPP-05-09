#pragma once

#include <iostream>
#include <stack>
#include <iterator>

template <typename T>
class MutantStack : public std::stack<T> {
private:

public:
    MutantStack() : std::stack<T>() {};
  //  MutantStack(const MutantStack &other) {};
  //  MutantStack &operator=(const MutantStack &other) {};
    ~MutantStack() {};

    // Iterator typedefs
    typedef typename std::stack<T>::container_type::iterator iterator;
    typedef typename std::stack<T>::container_type::const_iterator const_iterator;

    // Iterator functions
    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }
    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};