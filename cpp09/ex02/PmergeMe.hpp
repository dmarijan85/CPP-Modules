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


typedef typename std::vector<unsigned int> stduiVector;
typedef typename std::deque<unsigned int> stduiDeque;

class PmergeMe {
    public:
        PmergeMe(char **argv);
        PmergeMe(const PmergeMe& cpy);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe  &src);

        void sortAlg(void);



	private:
		stduiDeque	deq;
		stduiVector vec;
		float		vecTime;
		float	    deqTime;
		int         vecComp;

		//alg functions
		void mergeinsertVec(stduiVector &src);
		void firstPass(stduiVector &src);
		void fillNew(stduiVector &newSrc, stduiVector &main, stduiVector &pend);
		int  binarySearch(stduiVector &vec, int value, int searchLimit);




        //utils
        bool is_repeat(int n, stduiVector vec);
        bool is_valid(std::string arg);
        void switchGroups(int from, int to, int gSize, stduiVector &src);


};

void printVector(const stduiVector& vec);
#endif
