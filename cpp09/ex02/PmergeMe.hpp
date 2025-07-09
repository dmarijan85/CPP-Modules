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


typedef typename std::vector<unsigned int> stdVector;
typedef typename std::deque<unsigned int> stdDeque;

class PmergeMe {
    public:
        PmergeMe(char **argv);
        PmergeMe(const PmergeMe& cpy);
        ~PmergeMe();
        PmergeMe &operator=(const PmergeMe  &src);

        void sortVector(void);



	private:
		stdDeque	deq;
		stdVector   vec;
		float		vecTime;
		float	    deqTime;

		//alg functions
		stdVector firstPass(stdVector &src, int &gSize);

        //utils
        bool is_repeat(int n, stdVector vec);
        bool is_valid(std::string arg);
        void switchGroups(int from, int to, int gSize, stdVector &src);
        void printVector(const stdVector& vec);


};

#endif
