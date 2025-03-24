#include "Cat.hpp"

Cat::Cat(void) : Animal()
{
	std::cout << "Default Cat constructor called" << std::endl;
	this->type = "Cat:3";
	this->brainz = new Brain();
	return ;
}

Cat::Cat(const std::string type) : Animal("Custom")
{
	std::cout << "String Cat: " << type << " constructor called" << std::endl;
	this->type = type;
	this->brainz = new Brain();
	return ;
}

Cat::Cat(const Cat &cpy) : Animal(cpy)
{
	this->brainz = new Brain(*cpy.brainz);
	std::cout << "Copy Cat constructor called" << std::endl;
	*this = cpy;
	return ;
}

Cat::~Cat(void)
{
	std::cout << "Destructor Cat called" << std::endl;
	delete(this->brainz);
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
	std::cout  << "Cat assignment operator called" << std::endl;
	return *this;
}

Brain& Cat::getBrain(void)
{
	return *this->brainz;
}

void Cat::setBrain(const Brain &brainz)
{
	*this->brainz = brainz;
}
