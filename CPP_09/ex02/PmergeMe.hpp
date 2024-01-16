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
    PmergeMe(const PmergeMe &);
    PmergeMe& operator=(const PmergeMe &);
    ~PmergeMe();

    void sortVector(char **nbs);
    void sortDeque(char **nbs);
    template <typename Container> void mergeInsertSort(Container& sequence);
    template <typename Container> void displaySequence(const Container& sequence);


};