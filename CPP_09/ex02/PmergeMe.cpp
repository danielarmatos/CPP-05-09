#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {
}

PmergeMe::PmergeMe(const PmergeMe &other) {
	this->vector = other.vector;
	this->deque = other.deque;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &other) {
	this->vector = other.vector;
	this->deque = other.deque;
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
int PmergeMe::sortWithPair(Container& top, Container& bottom)
{
    int low = 0;
    int high = top.size() - 1;

    int target = *top.begin();
    //int itBottom = *bottom.begin();
    top.erase(top.begin());
    bottom.erase(bottom.begin());
    std::cout << "sortWithPair: " << target << std::endl;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (top[mid] == target) {
            return mid;
        } else if (top[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

template <typename Container>
void PmergeMe::pairAndSwap(Container& top, Container& bottom)
{
    std::cout << " ==========\nTop: " << std::endl;
    displaySequence(top);
    std::cout << "Bottom: " << std::endl;
    displaySequence(bottom);


    typename Container::iterator itTop = top.begin();
    typename Container::iterator itBottom = bottom.begin();

    while (itTop != top.end() && itBottom != bottom.end())
    {
        if (*itTop <= *itBottom)
        {
            std::swap(*itTop, *itBottom);
        }
        itTop++;
        itBottom++;
    }
    std::cout << "Top: " << std::endl;
    displaySequence(top);
    std::cout << "Bottom: " << std::endl;
    displaySequence(bottom);
    std::cout << " ==========" << std::endl;

}

template <typename Container>
void PmergeMe::mergeInsertSort(Container& sequence)
{
    if (sequence.size() <= 1)
        return ;

    // Split the sequence into two halves
    typename Container::iterator it = sequence.begin();
    Container top;
    Container bottom;
    while (it != sequence.end())
    {
        if (it == sequence.end() - 1)
        {
            // If the iterator points to the last element, push it to the bottom
            bottom.push_back(*it);
            break;
        }
        top.push_back(*it);
        it++;
        bottom.push_back(*it);
        it++;
    }

    // Make a pair for each two numbers and make a swap of necessary in order that the bigger number stays in the top sequence
    pairAndSwap(top, bottom);

    // Order the top sequence, maintaining the pair with the bottom sequence
    int res = sortWithPair(top, bottom);
    std::cout << "Res: " << res << std::endl;
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