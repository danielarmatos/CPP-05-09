#pragma once

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <ctime>

class Span {
private:
    unsigned int max;
    std::vector<int> numbers;

public:
    Span();
    Span(unsigned int max);
    Span(const Span &other);
    Span &operator=(const Span &other);
    ~Span();

    void addNumber(int n);
    void addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end);
    int shortestSpan();
    int longestSpan();

    class MaxElementsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };

    class MinElementsException : public std::exception {
    public:
        virtual const char *what() const throw();
    };
};