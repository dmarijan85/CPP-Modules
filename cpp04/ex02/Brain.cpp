#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain created by default" << std::endl;
}

Brain::Brain(const Brain& copy)
{
	std::cout << "Brain created with copy constructor" << std::endl;
	*this = copy;
}

Brain& Brain::operator=(const Brain& copy)
{
	if (this != &copy) {
		for (int i = 0; i < 100; i++) {
			this->ideas[i] = copy.ideas[i];
		}
	}
	std::cout << "Brain assigned via operator" << std::endl;
	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain deconstructd." << std::endl;
}

const std::string&	Brain::getIdeas(const int& i) const
{
	if (i >= 0 && i < 100) {
		return this->ideas[i];
	}
	return this->ideas[0];
}

void Brain::setIdeas(const std::string& idea, const int& i)
{
	if (i >= 0 && i < 100) {
		this->ideas[i] = idea;
	}
}
