#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *brainz;
public:
	Cat(void);
	Cat(const Cat &src);
	Cat(std::string str);
	~Cat(void);

	Cat & operator = (const Cat &src);
	void	makeSound(void) const;
	Brain	&getBrain(void);
	void	setBrain(const Brain &brainz);
};

#endif
