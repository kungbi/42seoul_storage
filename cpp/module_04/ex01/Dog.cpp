#include "Dog.hpp"

Dog::Dog() {
	type = "Dog";
	brain = new Brain();
	std::cout << "Dog constructor called" << std::endl;
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor called" << std::endl;
}

Dog::Dog(const Dog& c) {
	brain = new Brain();
	*this = c;
}

Dog& Dog::operator=(const Dog& c) {
	if (this == &c)
		return *this;

	type = c.type;
	if (brain)
		delete brain;
	brain = new Brain(*(c.brain));
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Woof woof" << std::endl;
}

Brain* Dog::getBrain() const {
	return brain;
}