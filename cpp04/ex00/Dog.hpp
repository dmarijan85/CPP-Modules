#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
public:
	Dog(void);
	Dog(const Dog &src);
	Dog(const std::string str);
	~Dog(void);

	Dog & operator = (const Dog &src);
	void	makeSound(void) const;
};

#endif
