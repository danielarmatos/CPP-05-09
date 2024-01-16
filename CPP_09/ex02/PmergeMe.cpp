#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &) {
}

PmergeMe& PmergeMe::operator=(const PmergeMe &) {
    return (*this);
}

PmergeMe::~PmergeMe() {
}

// ------------ //

template <typename Container>
void PmergeMe::displaySequence(const Container& sequence) {
    typename Container::const_iterator it;
    for (it = sequence.begin(); it != sequence.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& sequence) {
    if (sequence.size() <= 1)
        return ;

    // Split the sequence into two halves
    typename Container::iterator middle = sequence.begin() + sequence.size() / 2;
    Container left(sequence.begin(), middle);
    Container right(middle, sequence.end());

    // Recursively sort the two halves
    mergeInsertSort(left);
    mergeInsertSort(right);

    // Merge sort two containers into a single container.
    Container merged;
    std::merge(left.begin(), left.end(), right.begin(), right.end(), std::back_inserter(merged));
    std::swap(sequence, merged);
}

void PmergeMe::sortVector(char **nbs)
{
    std::clock_t start = std::clock();
    std::vector<int> vector;
    int size = 0;

    for (int i = 0; nbs[i]; i++)
    {
		vector.push_back(atoi(nbs[i]));
        size++;
    }

    this->vector = vector;
    mergeInsertSort(vector);

    std::clock_t end = std::clock();
    std::clock_t duration = end - start;

    std::cout << "After:  ";
    displaySequence(vector);

    std::cout   << "Time to process a range of " << size
                << " elements with std::vector : " << duration
                << " us" << std::endl;

}

void PmergeMe::sortDeque(char **nbs)
{
    std::clock_t start = std::clock();
    std::deque<int> deque;
    int size = 0;

    for (int i = 0; nbs[i]; i++)
    {
        deque.push_back(atoi(nbs[i]));
        size++;
    }

    this->deque = deque;
    mergeInsertSort(deque);

    //duration = std::clock() - duration;
    double duration = ( std::clock() - start );
    //double duration = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
    //   std::clock_t duration = end - start;

    //std::cout << "After2 :  ";
    //displaySequence(deque);

    std::cout   << "Time to process a range of " << size
                << " elements with std::deque : " << duration
                << " us" << std::endl;
}