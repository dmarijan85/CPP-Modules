#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
	this->type = "Default";
	return ;
}

Animal::Animal(std::string type)
{
	std::cout << "String Animal: " << type << " constructor called" << std::endl;
	this->type = type;
	return ;
}

Animal::Animal(const Animal &cpy)
{
	std::cout << "Copy Animal constructor called" << std::endl;
	*this = cpy;
	return ;
}

Animal::~Animal(void)
{
	std::cout << "Destructor Animal called" << std::endl;
	return ;
}
	

void Animal::setType(const std::string str)
{
	this->type = str;
}

std::string Animal::getType(void) const
{
	return (this->type);
}

void Animal::makeSound(void) const
{
	std::cout << this->type << " says: " << std::endl;
}

Animal& Animal::operator=(const Animal &copy) {
	if (this != &copy) {
		type = copy.type;
	}
	std::cout << "Assignement operator called for " << this->type << std::endl;
	return *this;
}
