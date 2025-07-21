#include "PmergeMe.hpp"
#include <stdexcept>

int main(int ac, char **av)
{
    try
    {
        if (ac < 2 || ac > 10000)
            throw std::runtime_error("Not enough numbers inputted!");
        PmergeMe    merge(&av[1]);
        merge.sortAlg();
    }
    catch (std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
