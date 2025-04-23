#ifndef INTERN_HPP
# define INTERN_HPP

# include "AForm.hpp"

# define NUM_FORMS 3

class Intern
{
  public:
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern(void);

	AForm *makeForm(const std::string &form_name, const std::string &target);

  private:
	static AForm *makeShrubberyForm(const std::string &target);
	static AForm *makeRobotomyForm(const std::string &target);
	static AForm *makePresidentialForm(const std::string &target);
};

#endif
