#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdio>
#include <ostream>
#include <stdexcept>

int calcJacob(int k) {
    if (k == 0) return 0;
    if (k == 1) return 1;
    return calcJacob(k-1) + 2 * calcJacob(k-2);
}

PmergeMe::PmergeMe(char **arg) {
	int n;
	int i;

	for (i = 0; arg[i]; i++) {
		n = atoi(arg[i]);
		if (!is_valid(arg[i]) || is_repeat(n, vec))
			throw std::runtime_error("Invalid input in sequence!");
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

void printVector(const stduiVector& vec)
{
    std::cout << "[";
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << vec[i];
        if (i != vec.size() - 1)
            std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}

bool PmergeMe::is_repeat(int n, stduiVector vec)
{
	return std::find(vec.begin(), vec.end(), static_cast<unsigned int>(n)) != vec.end();
}



// --------- ALG FUNCTIONS ------------

//sort by pairs :)
void PmergeMe::firstPass(stduiVector &src)
{
    for (int i = 0; i < src.size()-1; i += 2)
    {
        if (src[i] > src[i+1])
        {
            unsigned int temp = src[i];
            src[i] = src[i+1];
            src[i+1] = temp;
        }
    }
}


int PmergeMe::binarySearch(stduiVector &vec, int value, int searchLimit)
{
    int left = 0;
    int right = searchLimit+1;

    if (right >= (int)vec.size())
        right = (int)vec.size();

    while (left < right)
    {
        int mid = left + (right - left) / 2;

        if (vec[mid] < value) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }

    return left;
}

void merge(stduiVector &src, int left, int mid, int right)
{
    stduiVector temp;
    int i = left;
    int j = mid + 1;

    while (i <= mid && j <= right)
    {
        if (src[i] <= src[j])
            temp.push_back(src[i++]);
        else
            temp.push_back(src[j++]);
    }
}

void removeFront(stduiVector &vec, int n)
{
    if (n >= vec.size())
        vec.clear();
    else
    {
        std::move(vec.begin()+n, vec.end(), vec.begin());
        vec.resize(vec.size()-n);
    }
}

void PmergeMe::fillNew(stduiVector &newSrc, stduiVector &main, stduiVector &pend)
{
    if (pend.empty()) {
        newSrc = main;
        return;
    }

    newSrc.clear();
    newSrc.push_back(pend[0]);
    for (size_t i = 0; i < main.size(); i++) {
        newSrc.push_back(main[i]);
    }

    std::vector<bool> inserted(pend.size(), false);
    inserted[0] = true;
    int insertedCount = 1;
    int jacobIndex = 2;

    while (insertedCount < (int)pend.size())
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
            if (!inserted[pos])
            {
                // 1 for first pend, pos for main elements before it, insertedCount-1 for pend elements already inserted
                int searchLimit = 1 + pos + (insertedCount - 1);

                if (searchLimit >= newSrc.size())
                    searchLimit = newSrc.size() - 1;

                int insertPos = binarySearch(newSrc, pend[pos], searchLimit);
                newSrc.insert(newSrc.begin() + insertPos, pend[pos]);

                inserted[pos] = true;
                insertedCount++;
            }
        }
        jacobIndex++;
        if (jacobIndex > 20) break;
    }
}

void PmergeMe::mergeinsertVec(stduiVector &src)
{
    if (src.size() <= 1)
        return;

    //sort by pairs
    firstPass(src);

    stduiVector main, pend;
    for (int i = 0; i < (int)src.size(); i++)
    {
        if ((i % 2))
            main.push_back(src[i]);
        else
            pend.push_back(src[i]);
    }

    mergeinsertVec(main);

    stduiVector newSrc;
    fillNew(newSrc, main, pend);

    src = newSrc;
}

//driver function for the sort alg
void PmergeMe::sortAlg(void)
{
    std::cout << "Vector before sort: " << std::endl;
    printVector(vec);
    struct timeval start, end;

	gettimeofday(&start, NULL);
    mergeinsertVec(vec);
	gettimeofday(&end, NULL);

    std::cout << "Vector after sort: " << std::endl;
    printVector(vec);
    std::cout << "Time taken to sort the Vector: " << std::setprecision(5) << (end.tv_sec - start.tv_sec) * 1000000 + end.tv_usec - start.tv_usec << "ms" << std::endl;

}
