#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <ctime>
#include <algorithm>

class PmergeMe {
private:
    std::vector<int> vector;
    std::deque<int> deque;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &other);
    PmergeMe& operator=(const PmergeMe &other);
    ~PmergeMe();

    void sortVector(char **nbs);
    void sortDeque(char **nbs);
    template <typename Container> int sortWithPair(Container& top, Container& bottom);
    template <typename Container> void pairAndSwap(Container& top, Container& bottom);
    template <typename Container> void mergeInsertSort(Container& sequence);
    template <typename Container> void displaySequence(const Container& sequence);


};