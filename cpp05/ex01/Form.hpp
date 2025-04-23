#ifndef FORM_HPP
# define FORM_HPP

# include "Bureaucrat.hpp"
# include <iostream>

class	Bureaucrat;

class Form
{
	public:
		Form(void);
		Form(const std::string &name, int sign_grade, int exec_grade);
		Form(const Form &other);
		Form &operator=(const Form &other);
		~Form(void);

		const std::string &getName(void) const;
		bool isSigned() const;
		int getSignGrade() const;
		int getExecGrade() const;
		void beSigned(const Bureaucrat &bureaucrat);

		class GradeTooHighException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};

		class GradeTooLowException : public std::exception
		{
			public:
			const char *what(void) const throw();
		};

	private:
		const std::string	name_;
		bool				is_signed_;
		const int			sign_grade_;
		const int			exec_grade_;
};

std::ostream &operator<<(std::ostream &os, const Form &form);

#endif
