#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <iostream>

class Brain
{
private:
	std::string	ideas[100];
public:
	Brain(void);
	Brain(const Brain &src);
	Brain(std::string str);
	~Brain(void);

	Brain & operator = (const Brain &src);
	const std::string&	getIdeas(const int& i) const;
	void setIdeas(const std::string& idea, const int& i);
};

#endif
