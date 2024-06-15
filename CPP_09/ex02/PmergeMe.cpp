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
void PmergeMe::displaySequence(const Container& sequence)
{
    typename Container::const_iterator it;
    for (it = sequence.begin(); it != sequence.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

template <typename Container>
void PmergeMe::binarySearch(Container& ordered, int numb)
{
    if (ordered.empty())
    {
        ordered.push_back(numb);
    }
    else
    {
        int start = 0, end = ordered.size() - 1;
        int pos = 0;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;
            if (ordered[mid] == numb)
            {
                ordered.insert(ordered.begin() + std::max(0, mid + 1), numb);
                break;
            }
            else if (ordered[mid] > numb)
            {
                pos = end = mid - 1;
            }
            else
            {
                pos = start = mid + 1;
            }
            if (start > end)
            {
                pos = start;
                ordered.insert(ordered.begin() + std::max(0, pos), numb);
                break;
            }
        }
    }

}

template <typename Container>
void PmergeMe::binarySearchWithPair(Container& top, Container& bottom)
{
    int nTop = top.size();
    Container orderedTop;
    Container orderedBottom;

    for (int j = 0; j < nTop; j++)
    {
        if (orderedTop.empty())
        {
            orderedTop.push_back(top[j]);
            orderedBottom.push_back(bottom[j]);
        }
        else
        {
            int start = 0, end = orderedTop.size() - 1;
            int pos = 0;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (orderedTop[mid] == top[j])
                {
                    orderedTop.insert(orderedTop.begin() + std::max(0, mid + 1), top[j]);
                    orderedBottom.insert(orderedBottom.begin() + std::max(0, mid + 1), bottom[j]);
                    break;
                }
                else if (orderedTop[mid] > top[j])
                {
                    pos = end = mid - 1;
                }
                else
                {
                    pos = start = mid + 1;
                }
                if (start > end)
                {
                    pos = start;
                    orderedTop.insert(orderedTop.begin() + std::max(0, pos), top[j]);
                    orderedBottom.insert(orderedBottom.begin() + std::max(0, pos), bottom[j]);
                    break;
                }
            }
        }
    }
    top = orderedTop;
    bottom = orderedBottom;
}


/*
template <typename Container>
void PmergeMe::binarySearch(Container& top, int nTop, Container& bottom, int nBottom)
{
    (void) nBottom;
    Container orderedTop;
    Container orderedBottom;

    for (int j = 0; j < nTop; j++)
    {
        if (orderedTop.empty())
        {
            orderedTop.push_back(top[j]);
            orderedBottom.push_back(bottom[j]);
        }
        else
        {
            int start = 0, end = orderedTop.size() - 1;
            int pos = 0;

            while (start <= end)
            {
                int mid = start + (end - start) / 2;
                if (orderedTop[mid] == top[j])
                {
                    orderedTop.insert(orderedTop.begin() + std::max(0, mid + 1), top[j]);
                    orderedBottom.insert(orderedBottom.begin() + std::max(0, mid + 1), bottom[j]);
                    break;
                }
                else if (orderedTop[mid] > top[j])
                {
                    pos = end = mid - 1;
                }
                else
                {
                    pos = start = mid + 1;
                }
                if (start > end)
                {
                    pos = start;
                    orderedTop.insert(orderedTop.begin() + std::max(0, pos), top[j]);
                    orderedBottom.insert(orderedBottom.begin() + std::max(0, pos), bottom[j]);
                    break;
                }
            }
        }
    }
    top = orderedTop;
    bottom = orderedBottom;
}
*/

template <typename Container>
void PmergeMe::sortWithPair(Container& top, Container& bottom)
{
    bool containerIsOdd = false;
    int oddNumber;
    /*std::cout << "Display top sequence before: ";
    displaySequence(top);
    std::cout << "Display bottom sequence before: ";
    displaySequence(bottom);*/

    if (bottom.size() > top.size())
    {
        // If the number is odd, the bottom container will have one extra number that will be left out and added at the end again
        oddNumber = bottom.back();
        containerIsOdd = true;
    }
    binarySearchWithPair(top, bottom);
    if (containerIsOdd)
    {
        bottom.push_back(oddNumber);
    }
 /*   std::cout << "Display top sequence after: ";
    displaySequence(top);
    std::cout << "Display bottom sequence after: ";
    displaySequence(bottom);*/


}

/*template <typename Container>
int PmergeMe::sortWithPair(Container& top, Container& bottom)
{
    int low = 0;
    int high = top.size() - 1;

    Container orderedTop;
    Container orderedBottom;


    int target = *top.begin();
    //int itBottom = *bottom.begin();
    top.erase(top.begin());
    bottom.erase(bottom.begin());
    std::cout << "sortWithPair: " << target << std::endl;
    binarySearch(top, bottom, target);

   while (low <= high)
    {
        int mid = low + (high - low) / 2;
        std::cout << "mid: " << mid << " " << top[mid] << std::endl;
        if (top[mid] == target) {
            return mid;
        } else if (top[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
   return 0;
}*/

template <typename Container>
Container PmergeMe::createJacobsthalNumbers(int size)
{
    Container	jacob;
    Container	index;
    unsigned long k;
    int num = 0;
    int i = 0;

    jacob.push_back(0);
    jacob.push_back(1);
    for (; num < size;)
    {
        num = jacob.back() + (jacob[jacob.size() - 2] * 2);
        jacob.push_back(num);
    }
    index.push_back(1);
    for (k = 3; k < jacob.size(); k++)
    {
        i = jacob[k];
        num = jacob[k] - jacob[k - 1];
        for (int j = num; j > 0; j--)
            index.push_back(i--);
    }

    return index;
}

template <typename Container>
void PmergeMe::pairAndSwap(Container& top, Container& bottom)
{
    /*std::cout << " ==========\nTop: " << std::endl;
    displaySequence(top);
    std::cout << "Bottom: " << std::endl;
    displaySequence(bottom);*/


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
  /*  std::cout << "Top: " << std::endl;
    displaySequence(top);
    std::cout << "Bottom: " << std::endl;
    displaySequence(bottom);
    std::cout << " ==========" << std::endl;*/

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
    sortWithPair(top, bottom);

    // Use the Jacobsthal numbers to find out the order of the numbers we use for the
    // binary insertion from the bottom to the top container
    binarySearch(top, bottom[0]);
    int bottomSize = bottom.size();
    Container jacobsthal = createJacobsthalNumbers<Container>(bottomSize);
    for (int i = 0; i < bottomSize; i++)
    {
        int index = jacobsthal[i];
        //std::cout << "index: " << index << " numb: " << bottom[index] << std::endl;
        if (index < bottomSize)
            binarySearch(top, bottom[index]);
        //bottom.erase(bottom.begin() + index);
    }
    sequence = top;
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