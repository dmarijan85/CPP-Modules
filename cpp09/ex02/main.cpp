#include "PmergeMe.hpp"
#include <stdexcept>

int main(int ac, char **av)
{
    //return round((pow(2, k + 1) + pow(-1, k)) / 3);
    try
    {
        if (ac < 2 || ac > 10000)
            throw std::runtime_error("Come on man...");
        PmergeMe    merge(&av[1]);
        merge.sortVector();
        //merge.sortDeque();
    }
    catch (std::runtime_error &e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
