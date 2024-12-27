#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& dog) {
	*this = dog;
}

Dog& Dog::operator=(const Dog& dog) {
	type = dog.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}