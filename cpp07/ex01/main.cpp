#include "iter.hpp"
#include <iostream>

template <typename t1>
void print(t1 &x)
{
	std::cout << x << " ";
}

void	inc(int &x)
{
	x += 10;
}

int	main(void)
{
	int	tab[5] = {0, 1, 2, 3, 4};

	std::cout << "int array: ";
	iter(tab, 5, print);
	std::cout << "\n";

	iter(tab, 5, inc);
	std::cout << "int array after increment: ";
	iter(tab, 5, print);
	std::cout << "\n";

	std::string arr[5] = {"hello", "my", "name", "is", "jeff"};
	std::cout << "string array: ";
	iter(arr, 5, print);
	std::cout << "\n";
}
