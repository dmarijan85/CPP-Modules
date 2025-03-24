#include "WrongCat.hpp"

WrongCat::WrongCat(void) {
	this->type = "WrongCat";
	std::cout << this->type << " created with default constructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& copy) : WrongAnimal(copy) {
	std::cout << this->type  << " created with copy constructor" << std::endl;
	*this = copy;
}

WrongCat& WrongCat::operator=(const WrongCat& copy) {
	if (this != &copy) {
		this->type = copy.type;
	}
	std::cout  << "WrongCat assignement operator called" << std::endl;
	return *this;
}

WrongCat::~WrongCat(void) {
	std::cout << "WrongCat deconstructor called" << std::endl;
}

void WrongCat::makeSound(void) const {
	std::cout << "NYA NYA NYA NYA NYA (im not a cat btw)" << std::endl;
}
