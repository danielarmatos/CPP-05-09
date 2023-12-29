#pragma once

#include <iostream>

template <typename T>
class Array
{
private:
    T* array;
    unsigned int arraySize;

public:
    Array();
    Array(unsigned int n);
    Array(const Array &other);
    Array &operator=(const Array &other);
    ~Array();

    // Subscript operator
    T& operator[](unsigned int index);

    unsigned int size() const;

    class OutOfBoundsException : public std::exception
    {
    public:
        virtual const char* what() const throw();
    };
};