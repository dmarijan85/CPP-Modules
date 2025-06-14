#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <stdexcept>
#include <algorithm>
#include <limits>
#include <iostream>

class Span
{
    private:
        unsigned int N;
        std::vector<int> numbers;
    public:
        Span(void);
        Span(unsigned int newN);
        ~Span();

        Span & operator = (const Span &src);
        void    addNumber(int nbr);
        long    shortestSpan(void);
        long    longestSpan(void);

        void    printVector(void);
        void    fill_vector(unsigned int howMany);
};

#endif
