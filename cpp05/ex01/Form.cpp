#include "Form.hpp"

Form::Form(void) : name_("unnamed"), is_signed_(false), sign_grade_(MAX_GRADE),
	exec_grade_(MIN_GRADE)
{
}

Form::Form(const std::string &name, int sign_grade,
	int exec_grade) : name_(name), is_signed_(false), sign_grade_(sign_grade),
	exec_grade_(exec_grade)
{
	if (sign_grade < MAX_GRADE || exec_grade < MAX_GRADE)
		throw GradeTooHighException();
	else if (sign_grade > MIN_GRADE || exec_grade > MIN_GRADE)
		throw GradeTooLowException();
}

Form::Form(const Form &other) : name_(other.name_),
	is_signed_(other.is_signed_), sign_grade_(other.sign_grade_),
	exec_grade_(other.exec_grade_)
{
}

Form &Form::operator=(const Form &other)
{
	if (this == &other)
		return (*this);
	is_signed_ = other.is_signed_;
	return (*this);
}

Form::~Form(void)
{
}

const std::string &Form::getName(void) const
{
	return (name_);
}

bool Form::isSigned() const
{
	return (is_signed_);
}

int Form::getSignGrade(void) const
{
	return (sign_grade_);
}

int Form::getExecGrade(void) const
{
	return (exec_grade_);
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > sign_grade_)
		throw (GradeTooLowException());
	is_signed_ = true;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Form grade is too high!");
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Form grade is too low!");
}

std::ostream &operator<<(std::ostream &os, const Form &form)
{
	os << "Form \"" << form.getName() << "\", sign grade ";
	os << form.getSignGrade() << ", execution grade " << form.getExecGrade();
	os << ", is signed: " << (form.isSigned() ? "yes" : "no");
	return (os);
}
