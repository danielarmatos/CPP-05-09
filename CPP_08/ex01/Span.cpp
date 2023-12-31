#include "Span.hpp"

Span::Span()
    : max(0), numbers(0)
{
}

Span::Span(unsigned int max)
        : max(max), numbers(0)
{
}

Span::Span(const Span& other)
        : max(other.max), numbers(other.numbers)
{
}

Span& Span::operator=(const Span &other)
{
    max = other.max;
    numbers = other.numbers;
    return (*this);
}

Span::~Span() {
}

// -------------------------- //


void Span::addNumber(int n) {
    if (numbers.size() >= max)
        throw Span::MaxElementsException();
    numbers.push_back(n);
}

void Span::addNumbers(std::vector<int>::iterator begin, std::vector<int>::iterator end) {
    size_t newSize = numbers.size() + std::distance(begin, end);

    if (newSize > max)
        throw Span::MaxElementsException();

    numbers.insert(numbers.end(), begin, end);
}

int Span::longestSpan() {
    if (numbers.size() < 2)
        throw Span::MinElementsException();
    std::vector<int>::iterator maxElement = std::max_element(numbers.begin(), numbers.end());
    std::vector<int>::iterator minElement = std::min_element(numbers.begin(), numbers.end());

    return (*maxElement - *minElement);
}

int Span::shortestSpan() {
    if (numbers.size() < 2)
        throw Span::MinElementsException();
    std::vector<int> sortedNumbers = numbers;
    std::sort(sortedNumbers.begin(), sortedNumbers.end());

    int minSpan = longestSpan();
    for (size_t i = 1; i < sortedNumbers.size(); i++) {
        int span = sortedNumbers[i] - sortedNumbers[i - 1];
        if (span < minSpan) {
            minSpan = span;
        }
    }
    return (minSpan);
}

const char* Span::MaxElementsException::what() const throw() {
    return ("Maximum number of elements reached");
}

const char* Span::MinElementsException::what() const throw() {
    return ("Not enough elements to execute action");
}