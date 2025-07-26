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
		int         deqComp;

		//alg functions
		void mergeinsertVec(stdiVector &src);
		void firstPass(stdiVector &src);
		void fillNew(stdiVector &newSrc, stdiVector &main, stdiVector &pend);

		void firstPassDeq(stdiDeque &src);
		void mergeinsertDeq(stdiDeque &src);
		void fillNewDeq(stdiDeque &newSrc, stdiDeque &main, stdiDeque &pend);

		void sortVec(void);
		void sortDeq(void);

        //utils
        template<typename container> int binarySearch(container &vec, int value, int searchLimit);
        template<typename container> int findID(const container &newSrc, int biggerID);
        template<typename container> void swap(container &src, int og, int dest);
        template<typename container> bool is_sorted(const container& vec);
        template<typename container> bool is_repeat(int n, container vec);
        template <typename container> void printList(const container& vec);
        int calcJacob(int k);
        bool is_valid(std::string arg);


};

#endif
