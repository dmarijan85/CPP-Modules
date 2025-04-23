#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequest", 72,
	45), target_("default_target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequest",
	72, 45), target_(target)
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other),
	target_(other.target_)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	target_ = other.target_;
	return (*this);
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	checkExecution(executor);
	if (std::rand() & 1)
		std::cout << target_ << " has been robotomized successfully!\n";
	else
		std::cout << "Robotomy failed on " << target_ << "!\n";
}
