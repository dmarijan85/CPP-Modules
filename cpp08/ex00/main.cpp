#include "easyfind.hpp"
# include <iostream>
# include <list>
# include <vector>

int	main(void)
{
	std::vector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);
	std::vector<int>::iterator it(easyfind(vec, 5));
	if (it != vec.end())
		std::cout << "Found: " << *it << std::endl;
	else
		std::cout << "Not found\n";
	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);
	lst.push_back(40);
	lst.push_back(50);
	std::list<int>::iterator lst_it(easyfind(lst, 30));
	if (lst_it != lst.end())
		std::cout << "Found: " << *lst_it << std::endl;
	else
		std::cout << "Not found\n";
	return (0);
}
