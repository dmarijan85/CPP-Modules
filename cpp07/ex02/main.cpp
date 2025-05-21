#include "Array.hpp"
#include <exception>
#include <iostream>

int	main(void)
{
    Array<int> empty;

    try {
        for (int i = 0; i < 42; i++)
            std::cout << empty[i] << std::endl;
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    Array<int> numbers(42);
	int *mirror(new int[42]);

	try {
        for (int i = 0; i < 42; i++)
        {
            mirror[i] = i;
            numbers[i] = i;
        }
        for (int i = 0; i < 42; i++)
        {
            std::cout << "Regular int array: "<< mirror[i] << std::endl;
            std::cout << "Custom int array: " << numbers[i] << std::endl;
        }
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout << std::endl;
    Array<int> copy(numbers);

    try {
            for (int i = 0; i < 42; i++)
               std::cout << "copy array: " << copy[i] << std::endl;
            std::cout << copy[-42];
        } catch (const std::exception &e) {
           std::cout << e.what() << std::endl;
       }

    delete [] mirror;
}
