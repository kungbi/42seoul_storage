#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& c) {
	*this = c;
}

Dog& Dog::operator=(const Dog& c) {
	type = c.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}