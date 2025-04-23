#include "AForm.hpp"

AForm::AForm(void) : name_("unnamed"), is_signed_(false), sign_grade_(MAX_GRADE),
	exec_grade_(MIN_GRADE)
{
}

AForm::AForm(const std::string &name, int sign_grade,
	int exec_grade) : name_(name), is_signed_(false), sign_grade_(sign_grade),
	exec_grade_(exec_grade)
{
	if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
		throw GradeTooLowException();
}

AForm::AForm(const AForm &other) : name_(other.name_),
	is_signed_(other.is_signed_), sign_grade_(other.sign_grade_),
	exec_grade_(other.exec_grade_)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this == &other)
		return (*this);
	is_signed_ = other.is_signed_;
	return (*this);
}

AForm::~AForm(void)
{
}

const std::string &AForm::getName(void) const
{
	return (name_);
}

bool AForm::isSigned() const
{
	return (is_signed_);
}

int AForm::getSignGrade(void) const
{
	return (sign_grade_);
}

int AForm::getExecGrade(void) const
{
	return (exec_grade_);
}

void AForm::checkExecution(const Bureaucrat &executor) const
{
	if (is_signed_ == false)
		throw FormNotSignedException();
	if (executor.getGrade() > exec_grade_)
		throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade_)
		throw (GradeTooLowException());
	is_signed_ = true;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high!");
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low!");
}

const char *AForm::FormNotSignedException::what(void) const throw()
{
	return ("Form is not signed yet!");
}

std::ostream &operator<<(std::ostream &os, const AForm &form)
{
	os << "Form \"" << form.getName() << "\", sign grade ";
	os << form.getSignGrade() << ", execution grade " << form.getExecGrade();
	os << ", is signed: " << (form.isSigned() ? "yes" : "no");
	return (os);
}
