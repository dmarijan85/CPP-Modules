#include "Dog.hpp"

Dog::Dog(void) : Animal()
{
	std::cout << "Default Dog constructor called" << std::endl;
	this->type = "Doggo";
	this->brainz = new Brain();
	return ;
}

Dog::Dog(const std::string type) : Animal("Custom")
{
	std::cout << "String Dog: " << type << " constructor called" << std::endl;
	this->type = type;
	this->brainz = new Brain();
	return ;
}

Dog::Dog(const Dog &cpy) : Animal(cpy)
{
	this->brainz = new Brain(*cpy.brainz);
	std::cout << "Copy Dog constructor called" << std::endl;
	*this = cpy;
	return ;
}

Dog::~Dog(void)
{
	std::cout << "Destructor Dog called" << std::endl;
	delete(this->brainz);
	return ;
}

void Dog::makeSound(void) const
{
	std::cout << "WOOF WOOF" << std::endl;
}

Dog& Dog::operator=(const Dog& copy)
{
	if  (this != &copy) {
		this->type = copy.type;
	}
	std::cout << "Dog assignment operator called" << std::endl;
	return *this;
}

Brain& Dog::getBrain(void)
{
	return *this->brainz;
}

void Dog::setBrain(const Brain &brainz)
{
	*this->brainz = brainz;
}
