#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <ostream>
#include <stdexcept>

int calcJacob(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return calcJacob(k-1) + 2 * calcJacob(k-2);
}

PmergeMe::PmergeMe(char **arg) {
	ft_int n;
	int i;

	for (i = 0; arg[i]; i++) {
		n.value = atoi(arg[i]);
		if (!is_valid(arg[i]) || is_repeat(n.value, vec))
			throw std::runtime_error("Invalid input in sequence!");
		n.ID = i;
		n.biggerID = -1;
		this->deq.push_back(n);
		this->vec.push_back(n);
	}
	vecComp = 0;
}

PmergeMe::PmergeMe(const PmergeMe &cpy) { *this = cpy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy) {
	this->deq = cpy.deq;
	this->vec = cpy.vec;
	return *this;
}

//--------- UTILS -----------

//checks whether arg is a number
bool PmergeMe::is_valid(std::string arg)
{
	for (size_t i = 0; i < arg.size(); i++) {
		if (arg[i] < '0' || arg[i] > '9')
			return false;
	}
	return true;
}

void printVector(const stdiVector& vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i].value;
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

bool PmergeMe::is_repeat(int n, stdiVector vec)
{
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec[i].value == n) {
            return true;
        }
    }
    return false;
}

bool is_sorted(const stdiVector& vec)
{
    if (vec.size() <= 1)
        return true;

    for (size_t i = 0; i < vec.size() - 1; ++i)
        if (vec[i].value > vec[i+1].value)
            return false;

    return true;
}

void swap(stdiVector &src, int og, int dest)
{
    ft_int temp = src[og];
    src[og] = src[dest];
    src[dest] = temp;
}

int findID(const stdiVector &newSrc, int biggerID)
{
    for (size_t i = 0; i < newSrc.size(); i++)
        if (newSrc[i].ID == biggerID)
            return i;
    return -1;
}

// --------- ALG FUNCTIONS ------------

//sort by pairs :)
void PmergeMe::firstPass(stdiVector &src)
{
    for (size_t i = 0; i < src.size()-1; i += 2)
    {
        vecComp++;
        if (src[i].value > src[i+1].value)
            swap(src, i, i+1);
    }
}


int PmergeMe::binarySearch(stdiVector &vec, int value, int searchLimit)
{
    int left = 0;
    int right = searchLimit;

    if (right >= vec.size() || searchLimit == -1)
        right = vec.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;
        vecComp++;
        if (vec[mid].value < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

void PmergeMe::fillNew(stdiVector &newSrc, stdiVector &main, stdiVector &pend)
{
    if (pend.empty()) {
        newSrc = main;
        return;
    }

    newSrc.clear();
    for (size_t i = 0; i < main.size(); i++) {
        newSrc.push_back(main[i]);
    }

    if (newSrc.size() == 1 && pend.size() == 1)
    {
        newSrc.push_back(pend[0]);
        swap(newSrc, 0, 1);
        return ;
    }

    int insertedCount = 0;
    int jacobIndex = 1;

    while (insertedCount < pend.size())
    {
        int currentJacob = calcJacob(jacobIndex);
        int prevJacob = calcJacob(jacobIndex - 1);
        int maxPos;
        if (currentJacob - 1 < pend.size())
            maxPos = currentJacob - 1;
        else
            maxPos = pend.size() - 1;
        for (int pos = maxPos; pos >= prevJacob && pos >= 0; pos--)
        {
            int searchLimit = findID(newSrc, pend[pos].biggerID);

            int insertPos = binarySearch(newSrc, pend[pos].value, searchLimit);
            newSrc.insert(newSrc.begin() + insertPos, pend[pos]);
            insertedCount++;
        }
        jacobIndex++;
        if (jacobIndex > 20) break;
    }
}

void PmergeMe::mergeinsertVec(stdiVector &src)
{
    if (src.size() <= 1)
        return;

    firstPass(src);

    stdiVector main, pend;
    for (size_t i = 0; i < src.size(); i++)
    {
        if ((i % 2))
            main.push_back(src[i]);
        else
        {
            if (i+1 < src.size())
                src[i].biggerID = src[i+1].ID;
            pend.push_back(src[i]);
        }
    }

    mergeinsertVec(main);

    stdiVector newSrc;
    fillNew(newSrc, main, pend);

    src = newSrc;
}

void PmergeMe::sortVec(void)
{
    if (is_sorted(vec))
    {
        std::cout << "Vector already sorted!" << std::endl;
        return ;
    }

    struct timeval start, end, temp;

    std::cout << "Vector before sort (size: " << vec.size() << "): " << std::endl;
    printVector(vec);

    gettimeofday(&start, NULL);
    mergeinsertVec(vec);
    gettimeofday(&end, NULL);

    long total_time = (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec;

    std::cout << "Vector after sort: " << std::endl;
    printVector(vec);
    std::cout << "Number of comparisons: " << vecComp << std::endl;
    std::cout << "Time taken: " << total_time << " microseconds (" << total_time/1000.0 << "ms)" << std::endl;

}

void PmergeMe::sortAlg()
{
    sortVec();
}
