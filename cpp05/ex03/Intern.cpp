#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	static_cast<void>(other);
}

Intern &Intern::operator=(const Intern &other)
{
	static_cast<void>(other);
	return (*this);
}

Intern::~Intern()
{
}

AForm *Intern::makeForm(const std::string &form_name, const std::string &target)
{
	const std::string form_names[NUM_FORMS] = {"shrubbery creation",
		"robotomy request", "presidential pardon"};
	AForm *(*form_creators[NUM_FORMS])(const std::string &) = {&Intern::makeShrubberyForm,
		&Intern::makeRobotomyForm, &Intern::makePresidentialForm};
	for (size_t i(0); i < NUM_FORMS; i++)
	{
		if (form_name == form_names[i])
		{
			std::cout << "Intern creates " << form_names[i] << '\n';
			return (form_creators[i](target));
		}
	}
	std::cout << "Intern could not find the form type: " << form_name << '\n';
	return (0);
}

AForm *Intern::makeShrubberyForm(const std::string &target)
{
	return (new ShrubberyCreationForm(target));
}

AForm *Intern::makeRobotomyForm(const std::string &target)
{
	return (new RobotomyRequestForm(target));
}

AForm *Intern::makePresidentialForm(const std::string &target)
{
	return (new PresidentialPardonForm(target));
}
