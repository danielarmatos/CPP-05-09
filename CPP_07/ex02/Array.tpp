#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(new T[0]), arraySize(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), arraySize(n)
{
    for (unsigned int i = 0; i < n; i++) {
        array[i] = 0;
    }
}

template <typename T>
Array<T>::Array(const Array& other) : array(new T[other.arraySize]), arraySize(other.arraySize) {
    for (unsigned int i = 0; i < arraySize; i++) {
        array[i] = other.array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
    if (this == &other)
        return (*this);

    if (array)
        delete[] array;
    arraySize = other.arraySize;
    array = new T[other.arraySize];

    for (unsigned int i = 0; i < other.arraySize; i++) {
        array[i] = other.array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array() {
    if (array)
        delete[] array;
}

// -------------------------- //

template <typename T>
T& Array<T>::operator[](unsigned int index)
{
    if (index >= arraySize) {
        throw Array<T>::OutOfBoundsException();
    }
    return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->arraySize);
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
    return ("Index out of bounds");
}