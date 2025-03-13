#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Default Animal constructor called" << std::endl;
	return ;
}

Animal::Animal(std::string type)
{
	std::cout << "String Animal: " << type << " constructor called" << std::endl;
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
