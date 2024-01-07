#pragma once

#include <iostream>
#include <set>
#include <vector>
#include <deque>

class PmergeMe {
private:
    std::set<int> set;
    std::vector<int> vector;
    std::deque<int> deque;

public:
    PmergeMe();
    PmergeMe(const PmergeMe &);
    PmergeMe& operator=(const PmergeMe &);
    ~PmergeMe();

};