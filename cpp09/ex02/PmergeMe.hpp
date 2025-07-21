#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <deque>
# include <vector>
# include <sys/time.h>
# include <iomanip>
# include <algorithm>
# include <climits>
# include <error.h>
# include <math.h>

struct ft_int
{
    int value;
    int ID;
    int biggerID;
};

typedef typename std::vector<ft_int> stdiVector;
typedef typename std::deque<ft_int> stdiDeque;

class PmergeMe {
    public:
        PmergeMe(char **argv);
        PmergeMe(const PmergeMe& cpy);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe  &src);

        void sortAlg(void);



	private:
		stdiDeque	deq;
		stdiVector  vec;
		float		vecTime;
		float	    deqTime;
		int         vecComp;

		//alg functions
		void mergeinsertVec(stdiVector &src);
		void firstPass(stdiVector &src);
		void fillNew(stdiVector &newSrc, stdiVector &main, stdiVector &pend);
		int  binarySearch(stdiVector &vec, int value, int searchLimit);

		void sortVec(void);

        //utils
        bool is_repeat(int n, stdiVector vec);
        bool is_valid(std::string arg);
        void switchGroups(int from, int to, int gSize, stdiVector &src);


};

void printVector(const stdiVector& vec);
#endif
