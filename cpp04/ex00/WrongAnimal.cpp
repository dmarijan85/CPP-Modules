#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {
	std::cout << "WrongAnimal default constructor called " << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy) : type(copy.type) {
	std::cout << "WrongAnimal copy constructor called with " << this->type << std::endl;
	*this = copy;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &copy) {
	if (this != &copy) {
		type = copy.type;
	}
	std::cout << "Assignment operator called for " << this->type << std::endl;
	return *this;
}

WrongAnimal::~WrongAnimal(void) {
	std::cout << "WrongAnimal destructor called on " << this->type << std::endl;
}

std::string WrongAnimal::getType(void) const {
	return this->type;
}

void WrongAnimal::setType(std::string type) {
	this->type = type;
}

void WrongAnimal::makeSound(void) const {
	std::cout << this->type << " says: " << std::endl;
}
