#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Bureaucrat mario("Mario", 5);
	Bureaucrat luigi("Luigi", 145);
	ShrubberyCreationForm shrubbery("Toad");
	RobotomyRequestForm robotomy("Wario");
	PresidentialPardonForm pardon("Peach");
	mario.signAForm(shrubbery);
	luigi.signAForm(robotomy);
	mario.signAForm(pardon);
	mario.executeForm(shrubbery);
	mario.executeForm(robotomy);
	mario.executeForm(pardon);
	return (0);
}
