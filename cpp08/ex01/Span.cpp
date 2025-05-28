#include "Span.hpp"
#include <limits>

Span::Span()
{
    N = 0;
}

Span::Span(unsigned int newN)
{
    N = newN;
    numbers.reserve(newN);
}

Span::~Span()
{
    return ;
}

Span & Span::operator = (const Span &src)
{
    if (this != &src)
    {
        N = src.N;
        numbers = src.numbers;
    }
    return *this;
}

void Span::addNumber(int nbr)
{
    if (numbers.size() >= N)
        throw std::out_of_range("Span is full");
    numbers.push_back(nbr);
}

int Span::shortestSpan(void)
{
    if (numbers.size() < 2)
        throw std::out_of_range("Span is too short");

    std::vector<int> sorted(numbers);
    std::sort(sorted.begin(), sorted.end());
    int minSpan = std::numeric_limits<int>::max();
    for (std::vector<int>::iterator it = sorted.begin(); it != sorted.end() - 1; ++it)
        minSpan = std::min(minSpan, *(it + 1) - *it);

    return minSpan;
}

int Span::longestSpan(void)
{
    if (numbers.size() < 2)
        throw std::out_of_range("Span is too short");

    std::vector<int> sorted(numbers);
	std::sort(sorted.begin(), sorted.end());
	return (sorted[N - 1] - sorted[0]);
}

void Span::printVector(void)
{
	std::vector<int> tmp = this->numbers;
	std::sort(tmp.begin(), tmp.end());
	std::cout << "Numbers: ";
    for (std::vector<int>::iterator it = tmp.begin(); it != tmp.end(); ++it)
        std::cout << *it << " ";

    std::cout << std::endl;
}

void Span::addManyNumbers(int howMany)
{
    unsigned int seed = static_cast<unsigned int>(time(0));
    srand(seed);

    for (int i = 0; i < N; i++)
    {
            int randomNumber = rand() % 2147483647;
            numbers.push_back(randomNumber);
    }
    //printVector();
}
