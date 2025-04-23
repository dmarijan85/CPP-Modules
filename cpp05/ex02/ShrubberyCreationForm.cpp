#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreation",
	145, 137), target_("default_target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreation",
	145, 137), target_(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other),
	target_(other.target_)
{
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this == &other)
		return (*this);
	AForm::operator=(other);
	target_ = other.target_;
	return (*this);
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	checkExecution(executor);
	std::ofstream outfile((target_ + "_shrubbery").data());
	if (outfile.is_open())
	{
		outfile << "          .  *  .    .    \n";
		outfile << "       .    *    .     *  \n";
		outfile << "    *   .    .  *   .     \n";
		outfile << "      .  *  .    .  *     \n";
		outfile << "   .      *     .    *  . \n";
		outfile << "      *    .  *    .     .\n";
		outfile << "        .  *  .  *   .    \n";
		outfile << "     .    *    .    *     \n";
		outfile << "        *  .    .  *  .   \n";
		outfile << "           .  *  .        \n";
		outfile << "            *    .        \n";
		outfile.close();
	}
}
