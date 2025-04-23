#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("PresidentialPardon",
	25, 5), target_("default_target")
{
}

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) : AForm("PresidentialPardon",
	25, 5), target_(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other) : AForm(other),
	target_(other.target_)
{
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	target_ = other.target_;
	return (*this);
}

void PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	checkExecution(executor);
	std::cout << target_ << " has been pardoned by Zaphod Beeblebrox.\n";
}
