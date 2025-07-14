#ifndef PMERGEME_HPP
#define PMERGEME_HPP

# include <iostream>
# include <cstdlib>
# include <deque>
# include <vector>
# include <sys/time.h>
# include <iomanip>
# include <algorithm>
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

        void sortVector(void);



	private:
		stduiDeque	deq;
		stduiVector vec;
		float		vecTime;
		float	    deqTime;

		//alg functions
		stduiVector firstPass(stduiVector &src, int &gSize);
		stduiVector secondPass(stduiVector &src, int &gSize);


        //utils
        bool is_repeat(int n, stduiVector vec);
        bool is_valid(std::string arg);
        void switchGroups(int from, int to, int gSize, stduiVector &src);


};

void printVector(const stduiVector& vec);
#endif
