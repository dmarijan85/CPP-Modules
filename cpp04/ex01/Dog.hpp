#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *brainz;
public:
	Dog(void);
	Dog(const Dog &src);
	Dog(const std::string str);
	~Dog(void);

	Dog & operator = (const Dog &src);
	void	makeSound(void) const;
	Brain	&getBrain(void);
	void	setBrain(const Brain &brainz);
};

#endif
