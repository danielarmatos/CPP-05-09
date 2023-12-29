//#pragma once

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(new T[0]), arraySize(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), arraySize(n)
{
}

template <typename T>
Array<T>::Array(const Array& other) : array(new T[other.arraySize]), arraySize(other.arraySize) {
    for (unsigned int i = 0; i < arraySize; i++) {
        array[i] = other.array[i];
    }
}

template <typename T>
Array<T>& Array<T>::operator=(const Array &other) {
    if (this != &other) {
        // Allocate new memory
        T *newArray = new T[other.arraySize];

        // Copy elements
        for (std::size_t i = 0; i < other.arraySize; ++i) {
            newArray[i] = other.array[i];
        }

        // Deallocate old memory
        delete[] array;

        // Update Array and size
        array = newArray;
        arraySize = other.arraySize;
    }
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
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
    if (index >= arraySize) {
        throw Array<T>::OutOfBoundsException();
    }
    return array[index];
}