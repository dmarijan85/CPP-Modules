#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat mario("Mario", 3);
		Form contract("Contract", 70, 1);
		std::cout << mario;
		std::cout << contract << '\n';
		mario.signForm(contract);
		std::cout << contract << '\n';
		Bureaucrat luigi("Luigi", 61);
		// Form contract("Contract", 5, 1);
		//Form illegal("black market", 1, 151);
		luigi.signForm(contract);
		Bureaucrat bad("apple", 150);
		Form another("another", 1, 1);
		bad.signForm(another);

	}
	catch (const std::exception &er)
	{
		std::cout << er.what() << '\n';
	}
	return (0);
}
