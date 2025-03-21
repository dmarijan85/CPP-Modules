#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat:3";
	return ;
}

Cat::Cat(const std::string type) : Animal("Custom")
{
	std::cout << "String Cat: " << type << " constructor called" << std::endl;
	this->type = type;
	return ;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = cpy;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat called" << std::endl;
	return ;
}

void Cat::makeSound(void) const
{
	std::cout << "meeeoOOOOOWWWW" << std::endl;
}

Cat& Cat::operator=(const Cat& copy)
{
	if (this != &copy) {
		this->type = copy.type;
	}
	std::cout  << "Cat assignement operator called" << std::endl;
	return *this;
}
