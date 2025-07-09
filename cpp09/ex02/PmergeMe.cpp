#include "PmergeMe.hpp"
#include <cstdio>
#include <ostream>
#include <stdexcept>

int calcJacob(int k)
{
    return round((pow(2, k + 1) + pow(-1, k)) / 3);
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
}

PmergeMe::PmergeMe(const PmergeMe &cpy) { *this = cpy; }

PmergeMe::~PmergeMe() {}

PmergeMe &PmergeMe::operator=(const PmergeMe &cpy) {
	this->deq = cpy.deq;
	this->vec = cpy.vec;
	return *this;
}

//checks whether arg is a number
bool PmergeMe::is_valid(std::string arg)
{
	for (size_t i = 0; i < arg.size(); i++) {
		if (arg[i] < '0' || arg[i] > '9')
			return false;
	}
	return true;
}

void PmergeMe::printVector(const stdVector& vec)
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

bool PmergeMe::is_repeat(int n, std::vector<unsigned int> vec)
{
	return std::find(vec.begin(), vec.end(), static_cast<unsigned int>(n)) != vec.end();
}

// from and to are the indexes for the rightmost numbers in their respective group
void PmergeMe::switchGroups(int startOne, int startTwo, int gSize, stdVector &src)
{
    stdVector temp(gSize);

    for (int i = 0; i < gSize; i++)
        temp[i] = src[startOne+i];

    for (int i = 0; i < gSize; i++)
        src[startOne+i] = src[startTwo+i];

    for (int i = 0; i < gSize; i++)
        src[startTwo+i] = temp[i];
}


stdVector PmergeMe::firstPass(stdVector &src, int &gSize)
{
    if (src.size() < gSize)
        return src;

    int i = 0;
    while (i < src.size())
    {
        int upperOne = i+gSize-1;
        int upperTwo = upperOne+gSize;
        if (upperOne < src.size() && upperTwo < src.size() && src.at(upperOne) > src.at(upperTwo))
        {
            //std::cout << "hello cro, comparing " << src.at(upperOne) << " and " << src.at(upperTwo) << std::endl;

            switchGroups(i, i+gSize, gSize, src);
        }
        i += gSize*2;
    }
    gSize *= 2;
    return (firstPass(src, gSize));
}

//driver function for the sort alg
void PmergeMe::sortVector(void)
{
    int gSize = 1;
    vec = firstPass(vec, gSize);
    printVector(vec);

}
