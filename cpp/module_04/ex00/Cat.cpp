#include "Cat.hpp"

Cat::Cat() {
	type = "Cat";
	std::cout << "Cat constructor called" << std::endl;
}

Cat::~Cat() {
	std::cout << "Cat destructor called" << std::endl;
}

Cat::Cat(const Cat& c) {
	*this = c;
}

Cat& Cat::operator=(const Cat& c) {
	type = c.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Meow meow" << std::endl;
}