#include "Animal.hpp"

Animal::Animal() : type("Animal") {
	std::cout << "Animal constructor called" << std::endl;
}

Animal::~Animal() {
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const Animal& a) {
	std::cout << "Animal copy constructor called" << std::endl;
	*this = a;
}

Animal& Animal::operator=(const Animal& a) {
	std::cout << "Animal assignation operator called" << std::endl;
	if (this == &a)
		return *this;
	type = a.type;
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::makeSound() const {
	std::cout << "Animal class can not make sound" << std::endl;
}