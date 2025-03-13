#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>

class Animal
{
protected:
	std::string type;
public:
	Animal(void);
	Animal(std::string type);
	Animal(const Animal &src);
	~Animal(void);

	Animal & operator = (const Animal &cpy);
};

#endif
