#include "PmergeMe.hpp"
#include <algorithm>
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

//startone and starttwo are indexes for the leftmost numbers in their respective group
void PmergeMe::switchGroups(int startOne, int startTwo, int gSize, stduiVector &src)
{
    stduiVector temp(gSize);

    for (int i = 0; i < gSize; i++)
        temp[i] = src[startOne+i];

    for (int i = 0; i < gSize; i++)
        src[startOne+i] = src[startTwo+i];

    for (int i = 0; i < gSize; i++)
        src[startTwo+i] = temp[i];
}

stduiVector PmergeMe::firstPass(stduiVector &src, int &gSize)
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

//grab b1 and a1, as well as all of the a groups.
void initVecs(stduiVector &comp, stduiVector &pend, const stduiVector &src, int gSize)
{
    int i;
    for (i = 0; i < gSize*2 && i < src.size(); i++)
        comp.push_back(src[i]);

    while (i < src.size() && !(i+gSize > src.size()))
    {
        if (!(i%gSize))
        {
            for (int start = i; i < start+gSize && i < src.size() && start+gSize <= src.size(); i++)
                pend.push_back(src[i]);
            for (int start = i; i < start+gSize && i < src.size() && start+gSize <= src.size(); i++)
                comp.push_back(src[i]);
        }
        else
            i++;
    }
}

void grabRemainder(const stduiVector &src, stduiVector &comp)
{
    if (!(comp.size() <= src.size()))
        throw std::runtime_error("Unexpected length of vectors post insertion!");
    else
    {
        while (comp.size() < src.size())
            comp.push_back(src[comp.size()]);
    }
}

void insertGroup(stduiVector &pend, stduiVector &comp, int startPend, int startComp, int gSize)
{
    stduiVector temp;

    int i = 0;
    while (startComp + i < comp.size())
    {
        temp.push_back(comp[startComp+i]);
        i++;
    }
    while (i)
    {
        comp.pop_back();
        i--;
    }

    for (int i = 0; i < gSize; i++)
        comp.push_back(pend[startPend+i]);
    for (int i = 0; i < temp.size(); i++)
        comp.push_back(temp[i]);
}

void removeFront(stduiVector &vec, int n)
{

    if (n >= vec.size())
    {
        vec.clear();
        return;
    }
    std::move(vec.begin() + n, vec.end(), vec.begin());
    vec.resize(vec.size() - n);
}

void insertJacob(stduiVector &comp, stduiVector &pend, int topbound, int gSize)
{
    int howmany = topbound*gSize;

    if (topbound*gSize > pend.size())
        topbound = pend.size()/gSize;
    while (topbound > 0)
    {
        int upperComp= gSize-1;
        int upperPend = (topbound*gSize)-1;

        while (upperComp < comp.size())
        {
            if (pend[upperPend] < comp[upperComp])
            {
                insertGroup(pend, comp, upperPend-gSize+1, upperComp-gSize+1, gSize);
                break;
            }
            upperComp += gSize;
        }
        //if (i >= comp.size())
            //insertGroup(pend, comp, upperPend - gSize, comp.size(), gSize);
        topbound--;
    }

    removeFront(pend, howmany);
}

stduiVector PmergeMe::secondPass(stduiVector &src, int &gSize)
{
    stduiVector comp, pend;

    gSize /= 2;
    std::cout << "-----GSIZE: " << gSize << std::endl;
    initVecs(comp, pend, src, gSize);


    //insert method
    int jacobTurn = 2;
    while (!pend.empty())
    {
        std::cout << "turn number " << jacobTurn << std::endl;
        std::cout << "comp: " << std::endl;
        printVector(comp);
        std::cout << "pend: " << std::endl;
        printVector(pend);
        insertJacob(comp, pend, calcJacob(jacobTurn) - calcJacob(jacobTurn-1), gSize);
        jacobTurn++;
        std::cout << "comp after jacobinsert: " << std::endl;
        printVector(comp);
    }

    //grabRemainder(src, comp);

    if (gSize > 1)
        return (secondPass(comp, gSize));
    return comp;
}

//driver function for the sort alg
void PmergeMe::sortVector(void)
{
    int gSize = 1;
    vec = firstPass(vec, gSize);
    printVector(vec);
    vec = secondPass(vec, gSize);


}
