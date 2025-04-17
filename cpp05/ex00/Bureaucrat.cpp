#include "Bureaucrat.hpp"
#include <ostream>

std::string Bureaucrat::getName(void) const
{
    return _name;
}

int         Bureaucrat::getGrade(void) const
{
    return _grade;
}

std::ostream & operator << (std::ostream &out, Bureaucrat brc)
{
    out << brc.getName() << " , bureaucrat grade " << brc.getGrade() << std::endl;
    return (out);
}

Bureaucrat & Bureaucrat::operator = (const Bureaucrat &other)
{
	if (this == &other)
		return (*this);
	_grade = other._grade;
	return (*this);
}

void    Bureaucrat::incrementGrade(void)
{
    if (_grade <= 1)
        throw(_grade);
    _grade--;
}

void    Bureaucrat::decrementGrade(void)
{
    if (_grade >= 150)
        throw(_grade);
    _grade++;
}
