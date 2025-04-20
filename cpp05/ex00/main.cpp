#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat mario("Mario", 3);
		std::cout << mario << '\n';
		mario.incrementGrade();
		std::cout << mario << '\n';
		mario.decrementGrade();
		mario.decrementGrade();
		std::cout << mario << '\n';
		Bureaucrat luigi("Luigi");
		std::cout << luigi << '\n';
		Bureaucrat empty;
		std::cout << empty << '\n';
		Bureaucrat bad("apple", 150);
		std::cout << bad << '\n';
		bad.decrementGrade();
		std::cout << bad << '\n';
	}
	catch (const std::exception &er)
	{
		std::cout << er.what() << '\n';
	}
	return (0);
}
