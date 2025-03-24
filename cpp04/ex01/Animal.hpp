#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

#define RESET   "\033[0m"
#define BOLD     "\033[1m"
#define RED_BACKGROUND "\033[41m"
#define RED     "\033[31m"
#define BOLD_RED "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[34m"

#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

class Animal
{
protected:
	std::string type;

public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &src);
	virtual ~Animal(void);

	Animal & operator = (const Animal &cpy);

	void			setType(const std::string str);
	std::string		getType(void) const;
	virtual void	makeSound(void) const;
};

#endif
